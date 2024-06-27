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

int peek(struct stack* s, int pos) {
    int index = s->top - pos + 1;
    if (index < 0) {
        printf("Not a valid position for the stack\n");
        return -1;
    }
    else {
        return s->arr[index];
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

    // Printing values from the stack
    for (int i = 1; i <= s->top + 1; i++) {
        printf("The element at position %d is %d\n", i, peek(s, i));
    }

    return 0;
}