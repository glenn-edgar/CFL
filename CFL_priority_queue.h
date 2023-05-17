#ifndef __PRIORITY_HEAP_H__
#define __PRIORITY_HEAP_H__

#define __PRIORITY_HEAP_DEBUG__

typedef struct Node_cell_CFL_t
{
   unsigned short id;
   short forward;
   short backward;

   bool allocated;
} Node_cell_CFL_t;

typedef struct Node_control_CFL_t
{
   unsigned short size;
   short head;
   short tail;
   Node_cell_CFL_t *nodes;
   unsigned short *active_array;
} Node_control_CFL_t;

void PRH_enable_all_nodes_CFL(Node_control_CFL_t *node_control, unsigned number_of_nodes, Node_cell_CFL_t *nodes);

void PRH_disable_all_nodes_CFL(Node_control_CFL_t *node_control, unsigned number_of_nodes, Node_cell_CFL_t *nodes);

Node_cell_CFL_t *PRH_dequeue_node_CFL(Node_control_CFL_t *node_control, unsigned index);

void PRH_enqueue_node_CFL(Node_control_CFL_t *node_control, Node_cell_CFL_t *node);

unsigned short *PRH_generate_index_list(Node_control_CFL_t *node_control, unsigned short *number);

void PRH_verify_nodes_CFL(Node_control_CFL_t *node_control);
void PRH_print_forward_nodes_CFL(Node_control_CFL_t *node_control);
void PRH_print_backward_nodes_CFL(Node_control_CFL_t *node_control);

static inline Node_cell_CFL_t *PRH_return_node_CFL(Node_control_CFL_t *node_control, short index)
{

   return node_control->nodes + index;
}

static inline short PRH_return_first_node_CFL(Node_control_CFL_t *node_control)
{

   return node_control->head;
}

static inline short PRH_return_last_node_CFL(Node_control_CFL_t *node_control)
{

   return node_control->tail;
}

static inline short PRH_return_next_node_CFL(Node_cell_CFL_t *node)
{

   return node->forward;
}

static inline short PRH_return_previous_node_CFL(Node_cell_CFL_t *node)
{
   return node->backward;
}

#endif