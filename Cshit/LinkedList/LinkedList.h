#include <stdlib.h>
#include <memory.h>

typedef struct Node {
    struct Node* next;
    void* value;
} Node;

typedef struct LinkedList {
    Node* head;
    int size;
} LinkedList;

void push(LinkedList* list, void* valuePtr); // Pushes a node with valuePtr to the list
void* pop(LinkedList* list, int index); // Pops the head element of the LinkedList