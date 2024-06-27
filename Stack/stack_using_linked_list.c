#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void traverse(struct Node* top) {
    struct Node* p = top;
    
    while(p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}

int isEmpty(struct Node* top) {
    return top == NULL;
}

struct Node* push(struct Node* top, int data) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->next = top;
    top = n;

    return top;
}

/*
Using a double pointer (struct Node** top) in the pop function allows the function to modify
the original top pointer of the stack, ensuring that the stack's top
is correctly updated after a pop operation.
Using a single pointer would result in the function only modifying a local copy of the top pointer,
leaving the original stack's top pointer unchanged and leading to incorrect stack behavior.
*/
int pop(struct Node** top) {
    if (isEmpty(*top)) {
        printf("[Stack Underflow] Can't pop from an empty stack\n");
        return -1;
    } else {
        struct Node* n = *top;
        *top = (*top)->next;
        int value = n->data;
        free(n);

        return value;
    }
}

int main() {
    struct Node* top = NULL;

    top = push(top, 7);
    top = push(top, 11);
    top = push(top, 22);

    printf("Popped %d off the stack\n", pop(&top));

    traverse(top);

    return 0;
}