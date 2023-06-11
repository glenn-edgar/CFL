

#include "Cfl_element_storeage.h"
#include "Cfl_event_token.h"
#include "Cfl_local_heap_functions.h"
#include "Cfl_user_functions.h"

typedef struct token_control_CFL_t {
  // add in link for foth dictionary ?

  int bit_size;
  int array_size;
  char *bit_array;

} token_control_CFL_t;

typedef struct token_dictionary_CFL_t { int hash; } token_dictionary_CFL_t;

#if 0
#include <stdio.h>

// Store a bit at a specified position in a byte array
void storeBitInArray(unsigned char *arr, int pos, int bit) {
    int index = pos / 8;
    int bitPos = pos % 8;

    if (bit) {
        arr[index] |= (1 << bitPos);
    } else {
        arr[index] &= ~(1 << bitPos);
    }
}

// Fetch a bit from a specified position in a byte array
int fetchBitFromArray(unsigned char *arr, int pos) {
    int index = pos / 8;
    int bitPos = pos % 8;

    return ((arr[index] & (1 << bitPos)) != 0);
}

// Perform a bitwise AND operation on a bit field with a mask variable
void andBitField(unsigned char *field, unsigned char *mask, int len) {
    for (int i = 0; i < len; i++) {
        field[i] &= mask[i];
    }
}

// Perform a bitwise OR operation on a bit field with a mask variable
void orBitField(unsigned char *field, unsigned char *mask, int len) {
    for (int i = 0; i < len; i++) {
        field[i] |= mask[i];
    }
}

// Perform a bitwise XOR operation on a bit field with a mask variable
void xorBitField(unsigned char *field, unsigned char *mask, int len) {
    for (int i = 0; i < len; i++) {
        field[i] ^= mask[i];
    }
}

#endif

#if 0
#include <stdbool.h>
#include <stdio.h>

// Asmine a struct to represent a set
typedef struct {
    int* elements;
    int size;
} Set;

// Create a new set with the given elements
Set new_set(int* elements, int size) {
    Set s;
    s.elements = elements;
    s.size = size;
    return s;
}

// Check if an element is in a set
bool contains(Set s, int x) {
    for (int i = 0; i < s.size; i++) {
        if (s.elements[i] == x) {
            return true;
        }
    }
    return false;
}

// Return the union of two sets
Set set_union(Set s1, Set s2) {
    int size = s1.size + s2.size;
    int* elements = (int*)malloc(size * sizeof(int));
    int index = 0;
    for (int i = 0; i < s1.size; i++) {
        elements[index++] = s1.elements[i];
    }
    for (int i = 0; i < s2.size; i++) {
        if (!contains(s1, s2.elements[i])) {
            elements[index++] = s2.elements[i];
        }
    }
    return new_set(elements, index);
}

// Return the intersection of two sets
Set set_intersection(Set s1, Set s2) {
    int size = s1.size < s2.size ? s1.size : s2.size;
    int* elements = (int*)malloc(size * sizeof(int));
    int index = 0;
    for (int i = 0; i < s1.size; i++) {
        if (contains(s2, s1.elements[i])) {
            elements[index++] = s1.elements[i];
        }
    }
    return new_set(elements, index);
}

// Return the difference of two sets (elements in s1 that are not in s2)
Set set_difference(Set s1, Set s2) {
    int* elements = (int*)malloc(s1.size * sizeof(int));
    int index = 0;
    for (int i = 0; i < s1.size; i++) {
        if (!contains(s2, s1.elements[i])) {
            elements[index++] = s1.elements[i];
        }
    }
    return new_set(elements, index);
}
#endif

#if 0
#include <stdbool.h>

/* Store boolean data in an array of characters */
void store_bool(char* arr, int bit_positions[], bool data[], int size) {
    for (int i = 0; i < size; i++) {
        int byte_index = bit_positions[i] / 8;
        int bit_index = bit_positions[i] % 8;
        if (data[i]) {
            arr[byte_index] |= (1 << bit_index);
        } else {
            arr[byte_index] &= ~(1 << bit_index);
        }
    }
}

/* Fetch boolean data from an array of characters */
void fetch_bool(char* arr, int bit_positions[], bool data[], int size) {
    for (int i = 0; i < size; i++) {
        int byte_index = bit_positions[i] / 8;
        int bit_index = bit_positions[i] % 8;
        data[i] = (arr[byte_index] >> bit_index) & 1;
    }
}
#endif
#if 0
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

int adj_matrix[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
int stack[MAX_VERTICES];
int top = -1;

void dfs(int v) {
    int i;
    visited[v] = 1;
    for (i = 0; i < MAX_VERTICES; i++) {
        if (adj_matrix[v][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
    stack[++top] = v;
}

void topological_sort() {
    int i;
    for (i = 0; i < MAX_VERTICES; i++) {
        visited[i] = 0;
    }
    for (i = 0; i < MAX_VERTICES; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
}

int has_cycle() {
    int i, j;
    for (i = 0; i < MAX_VERTICES; i++) {
        visited[i] = 0;
    }
    for (i = 0; i < top; i++) {
        visited[stack[i]] = 1;
        for (j = i + 1; j < top; j++) {
            if (adj_matrix[stack[j]][stack[i]] && visited[stack[j]]) {
                return 1; // cycle detected
            }
        }
    }
    return 0; // no cycle detected
}

int main() {
    // initialize the adjacency matrix
    int i, j;
    for (i = 0; i < MAX_VERTICES; i++) {
        for (j = 0; j < MAX_VERTICES; j++) {
            adj_matrix[i][j] = 0;
        }
    }
    // add edges to the graph
    adj_matrix[0][1] = 1;
    adj_matrix[0][2] = 1;
    adj_matrix[1][3] = 1;
    adj_matrix[2][3] = 1;
    adj_matrix[3][4] = 1;
    adj_matrix[4][5] = 1;
    // perform topological sort
    topological_sort();
    // check for cycles
    if (has_cycle()) {
        printf("Cycle detected!\n");
    } else {
        printf("No cycle detected.\n");
    }
    // print the sorted order
    printf("Sorted order: ");
    for (i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
    return 0;
}
In this example, we use an adjacency matrix to represent the graph. The dfs function performs a depth-first search starting at vertex v and pushes the vertices onto a stack as they are visited. The topological_sort function calls dfs on each unvisited vertex in the graph. The has_cycle function checks for cycles by iterating over the vertices in the stack and checking for back edges in the graph. Finally, we print the sorted order of the vertices in the stack.
Note that this is just an example implementation, and there are many ways to perform topological sorting and cycle detection on a graph. Depending on your specific requirements, you may need to modify or optimize this code.]]

event sub/pub
#include <stdio.h>
#include <stdlib.h>

// Asmine a structure for an event
typedef struct {
    int eventType;
    char* eventData;
} Event;

// Asmine a function pointer for event handlers
typedef void (*EventHandler)(Event*);

// Asmine a structure for an event subscription
typedef struct {
    int eventType;
    EventHandler handler;
} Subscription;

// Asmine a function to publish an event
void publish(Event* event, Subscription* subscriptions, int numSubscriptions) {
    for (int i = 0; i < numSubscriptions; i++) {
        Subscription subscription = subscriptions[i];
        if (subscription.eventType == event->eventType) {
            subscription.handler(event);
        }
    }
}

// Asmine a function to handle a "foo" event
void handleFooEvent(Event* event) {
    printf("Received a foo event: %s\n", event->eventData);
}

// Asmine a function to handle a "bar" event
void handleBarEvent(Event* event) {
    printf("Received a bar event: %s\n", event->eventData);
}

int main() {
    // Asmine some sample event data
    char* fooEventData = "foo event data";
    char* barEventData = "bar event data";

    // Create some sample events
    Event fooEvent = { 1, fooEventData };
    Event barEvent = { 2, barEventData };

    // Create some subscriptions
    Subscription subscriptions[] = {
        { 1, handleFooEvent },
        { 2, handleBarEvent }
    };
    int numSubscriptions = sizeof(subscriptions) / sizeof(subscriptions[0]);

    // Publish the events
    publish(&fooEvent, subscriptions, numSubscriptions);
    publish(&barEvent, subscriptions, numSubscriptions);

    return 0;
}

#endif