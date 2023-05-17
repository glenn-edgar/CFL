#include "Cfl_definitions.h"
#include "Cfl_user_functions.h"
#include "Cfl_debug.h"

static void check_node(Node_control_CFL_t *node_control, unsigned index) {
  Node_cell_CFL_t *node = node_control->nodes + index;

  if ((node->backward < -1) || (node->backward >= node_control->size)) {
    ASSERT_PRINT_INT("node backward is invalid",
                     node->backward);
  }
  if ((node->backward == -1) && (node->forward == -1)) {
    return;
  }
  if ((node->forward < -1) || (node->forward >= node_control->size)) {
    ASSERT_PRINT_INT( "node forward is invalid",
                     node->backward);
  }
  if ((node->forward == -1) && (node_control->tail != node->id)) {

    ASSERT_PRINT_INT( "node control tail is invalid",
                     node_control->tail);
  }
  if ((node->backward == -1) && (node_control->head != node->id)) {
    ASSERT_PRINT_INT("node control tail is invalid",
                     node_control->head);
  }
}
static void check_links(Node_control_CFL_t *node_control) {
  unsigned active_links = 0;
  unsigned inactive_links = 0;
  unsigned forward_links = 0;
  unsigned backward_links = 0;
  Node_cell_CFL_t *node;
  // verify node forward
  // verify node backward
  if (node_control->head >= node_control->size) {
    ASSERT_PRINT_INT( "node head exceeds node size",node_control->head);
  }
  if (node_control->tail >= node_control->size) {
    ASSERT_PRINT_INT( "node tail exceed node size", node_control->tail);
  }
  for (unsigned i = 0; i < node_control->size; i++) {
    node = node_control->nodes + 1;
    if (node->id >= node_control->size) {
      ASSERT_PRINT_INT("invalid node id", node->id);
    }
    check_node(node_control, i);
  }
  for (unsigned i = 0; i < node_control->size; i++) {
    node = node_control->nodes + i;
    if ((node->forward >= node_control->size) || (node->forward < -1)) {
      ASSERT_PRINT_INT("invalid node forward", node->id);
    }
    if ((node->backward >= node_control->size) || (node->backward < -1)) {
      ASSERT_PRINT_INT( "invalid node forward", node->id);
    }
    if (node->allocated == false) {
      inactive_links++;
    } else {
      active_links++;
    }
  }
  if ((active_links + inactive_links) != node_control->size) {
    ASSERT_PRINT_INT( "inactive + active != total nodes",
        (int)(node_control->size - (active_links + inactive_links)));
  }
  if (((active_links == 0) && (node_control->head == -1)) ||
      (node_control->tail == -1)) {
    if (node_control->head != node_control->tail) {
      ASSERT_PRINT_INT("head and tail not correct for empty queue",
                       node_control->tail);
    }
    return; // empty queue
  }

  node = node_control->nodes + node_control->head;
  if (node->backward != -1) {
    ASSERT_PRINT_INT( "invalid head node", node->id);
  }
  forward_links++;
  while (node->forward >= 0) {
    forward_links++;
    node = node_control->nodes + node->forward;
  }
  if (active_links != forward_links) {

    ASSERT_PRINT_INT("bad forward links", forward_links);
  }
  node = node_control->nodes + node_control->tail;
  if (node->forward != -1) {
    ASSERT_PRINT_INT("invalid tail node", node->id);
  }
  backward_links++;
  while (node->backward >= 0) {
    backward_links++;
    node = node_control->nodes + node->backward;
  }

  if (backward_links != forward_links) {
    ASSERT_PRINT_INT("bad backward links", forward_links);
  }
}

unsigned short *PRH_generate_index_list(Node_control_CFL_t *node_control,
                                        unsigned short *number) {
  unsigned short *temp = node_control->active_array;
  Node_cell_CFL_t *node;
  short next_element;
  *number = 0;
  next_element = node_control->head;
  while (next_element != -1) {
    *number += 1;
    *temp++ = next_element;
    node = node_control->nodes + next_element;
    next_element = node->forward;
  }
  return node_control->active_array;
}

void PRH_enable_all_nodes_CFL(Node_control_CFL_t *node_control,
                              unsigned number_of_nodes,
                              Node_cell_CFL_t *nodes) {
  node_control->size = number_of_nodes;
  node_control->nodes = nodes;
  node_control->head = 0;
  node_control->tail = number_of_nodes - 1;
  for (int i = 0; i < (int)number_of_nodes; i++) {
    nodes[i].allocated = true;
    nodes[i].id = i;
    nodes[i].forward = (i == (int)number_of_nodes - 1) ? -1 : i + 1;
    nodes[i].backward = i - 1;
  }
#ifdef __PRIORITY_HEAP_DEBUG__
  check_links(node_control);
#endif
}
void PRH_disable_all_nodes_CFL(Node_control_CFL_t *node_control,
                               unsigned number_of_nodes,
                               Node_cell_CFL_t *nodes) {
  node_control->size = number_of_nodes;
  node_control->nodes = nodes;
  node_control->head = -1;
  node_control->tail = -1;
  for (unsigned i = 0; i < number_of_nodes; i++) {
    nodes[i].allocated = false;
    nodes[i].id = i;
    nodes[i].forward = -1;
    nodes[i].backward = -1;
  }
#ifdef __PRIORITY_HEAP_DEBUG__
  check_links(node_control);
#endif
}

Node_cell_CFL_t *PRH_dequeue_node_CFL(Node_control_CFL_t *node_control,
                                      unsigned index) {

  if (index >= node_control->size) {
    ASSERT_PRINT_INT( "bad index", index);
    return NULL; // will not reach here -- included to suppress warning
  }

  Node_cell_CFL_t *node = node_control->nodes + index;

  if (node->allocated == false) {
    ASSERT_PRINT_INT( "node is already dequeued", node->id);
    return NULL; // will not reach here -- included to suppress warning
  }
#ifdef __PRIORITY_HEAP_DEBUG__
  check_node(node_control, index);
#endif

  if (node->forward != -1) {
    node_control->nodes[node->forward].backward = node->backward;
  } else {
    node_control->tail = node->backward;
  }

  if (node->backward != -1) {
    node_control->nodes[node->backward].forward = node->forward;
  } else {
    node_control->head = node->forward;
  }
  node->allocated = false;
  node->forward = -1;
  node->backward = -1;

#ifdef __PRIORITY_HEAP_DEBUG__
  check_links(node_control);
#endif
  return node;
}

void PRH_enqueue_node_CFL(Node_control_CFL_t *node_control,
                          Node_cell_CFL_t *node) {

  if (node->id >= node_control->size) {
    ASSERT_PRINT_INT("invalid node id", node->id);
  }
  if (node->allocated == true) {
    ASSERT_PRINT_INT("node hash is currently allocated",
                     node->id);
  }
#ifdef __PRIORITY_HEAP_DEBUG__
  check_links(node_control);
#endif
  short current = node_control->head;
  short previous = -1;

  while (current != -1 && node_control->nodes[current].id < node->id) {
    previous = current;
    current = node_control->nodes[current].forward;
  }

  // resolve backward links
  if (previous == -1) {

    node->backward = -1;
    node_control->head = node->id;
  } else {
    node->backward = node_control->nodes[previous].id,
    node_control->nodes[previous].forward = node->id;
  }
  if (current == -1) {
    node->forward = -1;
    node_control->tail = node->id;
  } else {
    if (current >= node_control->size) {
      ASSERT_PRINT_INT( "invalid node id", current);
    }
    node->forward = node_control->nodes[current].id;
    node_control->nodes[current].backward = node->id;
  }

  node->allocated = true;

#ifdef __PRIORITY_HEAP_DEBUG__
  check_links(node_control);
#endif
}

void PRH_verify_nodes_CFL(Node_control_CFL_t *node_control) {

  check_links(node_control);
}

void PRH_print_forward_nodes_CFL(Node_control_CFL_t *node_control) {
  Node_cell_CFL_t *node;
  short next_element;
  Printf_CFL("----- dumping priority queue \n");
  Printf_CFL("Head %d \n", node_control->head);
  Printf_CFL("Tail %d \n", node_control->tail);
  next_element = node_control->head;
  while (next_element != -1) {
    node = node_control->nodes + next_element;
    Printf_CFL("Node id %d forward %d backward %d \n", node->id,
                  node->forward, node->backward);
    next_element = node->forward;
  }
  Printf_CFL("--- done ----- \n");
}

void PRH_print_backward_nodes_CFL(Node_control_CFL_t *node_control) {
  Node_cell_CFL_t *node;
  short next_element;
  Printf_CFL("----- dumping priority queue tail first \n");
  Printf_CFL("Head %d \n", node_control->head);
  Printf_CFL("Tail %d \n", node_control->tail);
  next_element = node_control->tail;
  while (next_element != -1) {
    node = node_control->nodes + next_element;
    Printf_CFL("Node id %d forward %d backward %d \n", node->id,
                  node->forward, node->backward);
    next_element = node->backward;
  }
  Printf_CFL("--- done ----- \n");
}
