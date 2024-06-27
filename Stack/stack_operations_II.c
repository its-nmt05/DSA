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

int peek(struct Node* top, int pos) {
    struct Node* p = top;

    for(int i = 0; (i < pos - 1 && p != NULL); i++) {
        p = p-> next;
    }
    
    if (p != NULL) {
        return p->data;
    } else {
        return -1;
    }
}

int stackTop(struct Node* top) {
    if (isEmpty(top)) {
        printf("The stack is empty\n");
        return - 1;
    } else {
        return top->data;
    }
}

int stackBottom(struct Node* top) {
    if (isEmpty(top)) {
        printf("The stack is empty\n");
        return - 1;
    } else {
        struct Node* n = top;
        while(n->next != NULL) {
            n = n->next;
        }
        return n->data;
    }
}

int main() {
    struct Node* top = NULL;

    top = push(top, 7);
    top = push(top, 11);
    top = push(top, 22);

    // traverse(top);

    // printing the values in the stack
    // for (int i = 1; i <= 3; i ++) {
    //     printf("The value at position %d is: %d\n", i, peek(top, i));
    // }

    printf("The top most element of the stack is: %d\n", stackTop(top));
    printf("The bottom most element of the stack is: %d\n", stackBottom(top));

    return 0;
}