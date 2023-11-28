#include "LinkedList.h"
int main() {
    LinkedList list = { 0 };
    int value1 = 1;
    int value2 = 2;
    push(&list, &value1);
    push(&list, &value2);
    pop(&list, 0);
    pop(&list, list.size-1);
    pop(&list, 3);
    LinkedList val1, val2, listlist = { 0 };
    push(&listlist, &val1);
    push(&listlist, &val2);
}