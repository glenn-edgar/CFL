
#ifndef __CFL_DATA_LINKS_H__
#define __CFL_DATA_LINKS_H__
#if 0
#include "CFL_user_functions.h"

typedef struct LDE_results{
    unsigned number;
    void     **data_links;
}LDE_results;

typedef struct Linked_data_element_CFL_t Linked_data_element_CFL_t;

typedef void* (*LDE_fn)(void* handle,int id, void *user_data, unsigned count, void *results);

// Forward declaration

typedef struct Up_down_links_Cft_t {
    unsigned downward_count;
    Linked_data_element_CFL_t* forward;
    Linked_data_element_CFL_t* backward;
    Linked_data_element_CFL_t* downward;
    Linked_data_element_CFL_t* upward;
} Up_down_links_Cft_t;

// Now the full definition of Linked_data_element_CFL_t
struct Linked_data_element_CFL_t {
    bool         active;
    int          id;
    void*        user_data;
    void*        processed_data;
    LDE_fn       fn;
    LDE_results  *results;
    Up_down_links_Cft_t link;
};


static void LDE_pack_local_event(Event_data_CFL_t *event, Linked_data_element_CFL_t *node) {
    
    event->params = node;
}

static Linked_data_element_CFL_t* LDE_unpack_local_event(Event_data_CFL_t *event, Linked_data_element_CFL_t **node) {
    
    return (Linked_data_element_CFL_t *)event->params;
}

static inline void LDE_assign_fn_data_CFL(Linked_data_element_CFL_t* node, LDE_fn fn, void* data) {
    node->fn = fn;
    node->user_data = data;
}

static inline Linked_data_element_CFL_t* LDE_find_next_CFL_t(Linked_data_element_CFL_t* node) {
    return node->link.forward;
}

static inline Linked_data_element_CFL_t* LDE_find_bottom_CFL_t(Linked_data_element_CFL_t* node) {
    return node->link.downward;
}

// Remove the duplicate LDE_create_CFL function declaration
Linked_data_element_CFL_t* LDE_create_CFL(void* input, int id, LDE_fn fn, void* down_data, void* up_data);

void LDE_destroy_CFL(void* handle, Linked_data_element_CFL_t* node);

void LDE_attach_downward_CFL(Linked_data_element_CFL_t* parent_node, Linked_data_element_CFL_t* join_node);

void LDE_free_downward_link_CFL(void* handle, Linked_data_element_CFL_t* node);

void LDE_function_call_CFL(void* handle, Linked_data_element_CFL_t* node);

#endif
#endif