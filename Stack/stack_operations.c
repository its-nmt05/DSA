#include <stdio.h>
#include <stdlib.h>

struct stack {
    int size;
    int top;
    int* arr;
};

int isEmpty(struct stack* s) {
    return s->top == -1;
}

int isFull(struct stack* s) {
    return s->top == s->size - 1;
}

void push(struct stack* s, int value) {
    // check if the stack is already full or not
    if(isFull(s)) {
        printf("[Stack Overflow] Can't push %d to the stack\n", value);
    } else {
        s->arr[++s->top] = value;
    }
}

int pop(struct stack* s) {
    if(isEmpty(s)) {
        printf("[Stack Underflow] Can't pop from an empty stack\n");
        return -1;
    } else {
        // store the top most value of the stack
        int value = s->arr[s->top--];
        return value;
    }
}

int main() {
    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    push(s, 1);
    push(s, 3);
    push(s, 17);
    push(s, 23);
    push(s, 52);    // ---> Pushed 5 values to the stack

    push(s, 11);    // Stack overflow occurs, since size of the stack is only 5

    // pop() order : LIFO
    printf("Popped %d off the stack\n", pop(s));
    printf("Popped %d off the stack\n", pop(s));
    printf("Popped %d off the stack\n", pop(s));
    printf("Popped %d off the stack\n", pop(s));
    printf("Popped %d off the stack\n", pop(s));

    printf("Popped %d off the stack\n", pop(s)); // Stack underflow occurs, since stack is empty

    return 0;
}