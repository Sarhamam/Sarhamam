#include "LinkedList.h"

void push(LinkedList* list, void* valuePtr) {
    list->size += 1;
    Node* node = malloc(sizeof(Node));
    memset(node, 0, sizeof(Node));
    node->value = valuePtr;
    if (list->head == NULL) {
        list->head = node;
    } else {
        Node* current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
    }
}

void* pop(LinkedList* list, int index) {
    if (list->size <= index) {
        return NULL;
    }
    Node* current = list->head;
    Node* previousNode = NULL;
    for (int i=0; i<index; i++) {
        previousNode = current;
        current = current->next;
    }
    if (previousNode != NULL) {
        previousNode->next = current->next;
    }
    if (index == 0) {
        list->head = current->next;
    }
    void* value = current->value;
    free(current);
    list->size -= 1;
    return value;
}
