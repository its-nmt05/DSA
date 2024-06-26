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
    return s->top == (s->size - 1);
}

int main() {
    // struct stack s;
    // s.size = 80;
    // s.top = -1;
    // s.arr = (int *)malloc(s.size * sizeof(int));

    /*
        the advantage of using a pointer instead is that
        we can directly pass the stack into functions as a reference
    */ 
    struct stack* s;
    s->size = 80;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    // inserting element manually
    s->arr[++s->top] = 13;

    if(isEmpty(s)) {
        printf("The stack is empty");
    } else {
        printf("The stack is not empty");
    }

    return 0;
}