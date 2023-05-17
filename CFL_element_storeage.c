#include "Cfl_user_functions.h"


#include "Cfl_element_storeage.h"
#include "Cfl_hash_table_support.h"
#include "Cfl_local_heap_functions.h"

#define CELL_SAFETY 2
#define TABLE_EXPANSION(x) ((3 * x) / 2)
#define COMPUTE_HASH_INDEX(x, y) abs(y % TABLE_EXPANSION(x))

static void mark_hash_table(int cell_number, int *cells);
static void update_hash_table(Hash_cell_control_CFL_t *hash_cell_control,
                              Hash_cell_CFL_t *hash_cell);
static int compute_hash_index(Hash_cell_control_CFL_t *hash_cell_control,
                              int hash_value);
static int find_cell_location(Hash_cell_control_CFL_t *hash_cell_control,
                              int hash_index, int hash_value, const char *name);
static Hash_cell_CFL_t *
find_last_cell_location(Hash_cell_control_CFL_t *hash_cell_control, int index);
static int get_hash_value(Hash_cell_control_CFL_t *hash_cell,
                          int hash_table_index);
static void store_hash_value(Hash_cell_control_CFL_t *hash_cell,
                             int hash_table_index, int value);

static void mark_cell_id(int cell_number, Hash_cell_CFL_t *pointer);

Hash_cell_control_CFL_t *contruct_hash_cell_control_CFL( void *input,
                                                        int cell_number) {
  Handle_CFL_t *handle = (Handle_CFL_t *)input;                                                        
  Hash_cell_control_CFL_t *return_value;
  return_value = (Hash_cell_control_CFL_t *)allocate_once_CFL(
      handle, sizeof(Hash_cell_control_CFL_t));
  return_value->current_number = 0;
  return_value->max_number = cell_number;

  return_value->cell_array = (Hash_cell_CFL_t *)allocate_once_CFL(
      handle, sizeof(Hash_cell_CFL_t) * cell_number);
  return_value->hash_table = (int *)allocate_once_CFL(
      handle, sizeof(int) * TABLE_EXPANSION(cell_number));
  mark_cell_id(cell_number, return_value->cell_array);
  mark_hash_table(TABLE_EXPANSION(cell_number) + CELL_SAFETY,
                  return_value->hash_table);
  return return_value;
}

static void mark_cell_id(int cell_number, Hash_cell_CFL_t *pointer) {
  for (int i = 0; i < cell_number; i++) {
    pointer->id = i;
    pointer->link = -1;
    pointer++;
  }
}

static void mark_hash_table(int cell_number, int *cells) {

  for (int i = 0; i < cell_number; i++) {
    *cells = -1;
    cells++;
  }
}

void Store_Names_CFL(Hash_cell_control_CFL_t *hash_cell_control, int length,
                     const char **names) {

  for (int i = 0; i < length; i++) {

    Store_Name_CFL(hash_cell_control, *names);

    names++;
  }
}

int Store_Name_CFL(Hash_cell_control_CFL_t *hash_cell_control,
                   const char *name) {
  Hash_cell_CFL_t *hash_cell;

  if (Find_Name_CFL(hash_cell_control, name) >= 0) {
    ASSERT_PRINT("Duplicate Name", name);
  }

  if (hash_cell_control->current_number >= hash_cell_control->max_number) {
    ASSERT_PRINT( "Table is full adding", name);
  }

  hash_cell = hash_cell_control->cell_array + hash_cell_control->current_number;
  hash_cell_control->current_number += 1;
  hash_cell->name = name;
  hash_cell->hash = hash(name);
  hash_cell->link = -1;

  update_hash_table(hash_cell_control, hash_cell);
  return hash_cell->id;
}

int Find_Name_CFL(Hash_cell_control_CFL_t *hash_cell_control,
                  const char *name) {
  int hash_index;
  int hash_value;

  if (name == NULL) {
    ASSERT_PRINT(__func__, "null is not valid");
  }
  hash_value = hash(name);
  hash_index = compute_hash_index(hash_cell_control, hash_value);
  return find_cell_location(hash_cell_control, hash_index, hash_value, name);
}

/*
**  Make sure name exists
*/
int Validate_Name_CFL(Hash_cell_control_CFL_t *hash_cell_control,
                      const char *name) {
  int return_value;

  return_value = Find_Name_CFL(hash_cell_control, name);

  if (return_value < 0) {

    ASSERT_PRINT( "Name Not Found", name);
  }

  return return_value;
}

static void update_hash_table(Hash_cell_control_CFL_t *hash_cell_control,
                              Hash_cell_CFL_t *hash_cell) {
  Hash_cell_CFL_t *last_cell;
  int hash_index;
  hash_index = compute_hash_index(hash_cell_control, hash_cell->hash);

  last_cell = find_last_cell_location(hash_cell_control, hash_index);
  if (last_cell == NULL) {

    store_hash_value(hash_cell_control, hash_index, hash_cell->id);
  } else {

    last_cell->link = hash_cell->id;
  }
}

static int compute_hash_index(Hash_cell_control_CFL_t *hash_cell_control,
                              int hash_value) {

  return COMPUTE_HASH_INDEX(hash_cell_control->max_number, hash_value);
}

static int find_cell_location(Hash_cell_control_CFL_t *hash_cell_control,
                              int hash_index, int hash_value,
                              const char *name) {

  Hash_cell_CFL_t *hash_cell;
  if (get_hash_value(hash_cell_control, hash_index) < 0) {
    return -1;
  }
  hash_cell = hash_cell_control->cell_array +
              get_hash_value(hash_cell_control, hash_index);
  while (1) {
    if ((hash_cell->hash == hash_value) &&
        (strcmp(hash_cell->name, name) == 0)) {
      return hash_cell->id;
    }
    if (hash_cell->link >= 0) {
      hash_cell = hash_cell_control->cell_array + hash_cell->link;
    } else {
      return -1;
    }
  }
  return -1;
}

static Hash_cell_CFL_t *
find_last_cell_location(Hash_cell_control_CFL_t *hash_cell_control,
                        int hash_index) {

  Hash_cell_CFL_t *hash_cell;
  if (get_hash_value(hash_cell_control, hash_index) < 0) {
    return NULL;
  }
  hash_cell = hash_cell_control->cell_array +
              get_hash_value(hash_cell_control, hash_index);
  while (1) {

    if (hash_cell->link >= 0) {
      hash_cell = hash_cell_control->cell_array + hash_cell->link;
    } else {
      return hash_cell;
    }
  }
  return NULL;
}

static int get_hash_value(Hash_cell_control_CFL_t *hash_cell_ctrl,
                          int hash_table_index) {
  int value = *(hash_cell_ctrl->hash_table + hash_table_index);

  return value;
}

static void store_hash_value(Hash_cell_control_CFL_t *hash_cell_ctrl,
                             int hash_table_index, int value) {

  *(hash_cell_ctrl->hash_table + hash_table_index) = value;
}
