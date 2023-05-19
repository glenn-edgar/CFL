
#include "CFL_user_functions.h"
#include "CFL_data_links.h"
#if 0
Linked_data_element_CFL_t* LDE_create_CFL(void* input, int id, LDE_fn fn, void* user_data) {
  Linked_data_element_CFL_t* lde = (Linked_data_element_CFL_t*)Private_heap_malloc_CFL(input, sizeof(Linked_data_element_CFL_t));
  lde->id = id;
  lde->user_data = user_data;
  lde->processed_data = NULL;;
  lde->fn = fn;
  lde->results = NULL;
  lde->link.downward_count = 0;
  lde->link.forward = NULL;
  lde->link.backward = NULL;
  lde->link.downward = NULL;
  lde->link.upward = NULL;
  return lde; 
}




 
static inline void free_lde_results(void *handle,LDE_results* results) {
  if(results != NULL) {
    for(int i = 0; i < results->number; i++) {
      if(results->data_links[i] != NULL) {
        Private_heap_free_CFL(handle, results->data_links[i]);
      }
    }
    free(results->data_links);
    free(results);
  }
} 


void LDE_destroy_CFL(void* handle, Linked_data_element_CFL_t* node) {
  
  
  if (node->processed_data != NULL) {
    Private_heap_free_CFL(handle, node->processed_data);
  }
  
  if(node->results != NULL) {
    free_lde_results(handle,node->results);
  }
  Private_heap_free_CFL(handle, node);
}

void LDE_attach_downward_CFL(Linked_data_element_CFL_t* parent_node, Linked_data_element_CFL_t* join_node) {
  // Check if the parent_node's downward_link is NULL
  parent_node->link.downward_count += 1;
  if (parent_node->link.downward == NULL) {
    // If it is NULL, set the downward_link to join_node and update the upward_link of join_node
    parent_node->link.downward = join_node;
    join_node->link.upward = parent_node;

  }
  else {
    // If it's not NULL, follow the forward_link to the end and attach the join_node using the forward and backward_link
    Linked_data_element_CFL_t* current_node = parent_node->link.downward;

    // Traverse to the end of the list
    while (current_node->link.forward != NULL) {
      current_node = current_node->link.forward;
    }

    // Attach join_node to the end of the list
    current_node->link.forward = join_node;
    join_node->link.backward = current_node;
    join_node->link.upward = NULL;

  }
}


void LDE_free_downward_link_CFL(void* handle, Linked_data_element_CFL_t* node) {
  // Check if the downward_link is NULL
  if (node->link.downward == NULL) {
    return;
  }

  // Follow node->link.downward and then follow forward_links and downward_links to free nodes
  Linked_data_element_CFL_t* current_downward_node = node->link.downward;
  while (current_downward_node != NULL) {
    Linked_data_element_CFL_t* next_downward_node = current_downward_node->link.downward;
    Linked_data_element_CFL_t* current_forward_node = current_downward_node;

    while (current_forward_node != NULL) {
      Linked_data_element_CFL_t* next_forward_node = current_forward_node->link.forward;

      // Free the nodes in the downward direction of the current_forward_node
      LDE_free_downward_link_CFL(handle, current_forward_node);

      // Free the current node using my_free(handle)
      LDE_destroy_CFL(handle, current_forward_node);

      current_forward_node = next_forward_node;
    }

    // Move to the next downward node
    current_downward_node = next_downward_node;
  }
}



static void inline assemble_results(void *handle, Linked_data_element_CFL_t* node){
  if(node->link.downward_count == 0){
    node->results = NULL;
    return;
  }
  node->results = (LDE_results *)malloc(sizeof(LDE_results)); // Allocate memory for results
  node->results->number = node->link.downward_count; // Set the number of results
  node->results->data_links = (void **)malloc(sizeof(void *) * node->link.downward_count); // Allocate memory for data_links array
  int i = 0;
  Linked_data_element_CFL_t* current_node = node->link.downward;
  while(current_node != NULL){
    node->results->data_links[i] = current_node->processed_data;
    current_node = current_node->link.forward;
    i++;
  }
} 


void LDE_function_call_CFL(void* handle, Linked_data_element_CFL_t* node){
   if(node->fn == NULL){
      node->results = NULL;
      return;
   }
   assemble_results(handle, node);
   // make function call
   node->processed_data = node->fn(handle,node->id, node->user_data, node->link.downward_count, node->results);   
   node->active = true;
}






 
// ...



// ...
#endif