#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

void traverse(struct Node* head) {
    struct Node* p = head;

    while(p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}

// reversing the doubly linked list 
struct Node* reverse(struct Node* head) {
    struct Node* p = head;

    while(p != NULL) {
        struct Node* temp = p->next;
        p->next = p->prev;
        p->prev = temp;

        head = p;
        p = temp;
    }
    return head;
}

int main() {
    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;
    
    // allocating dynamic memeory for nodes in Heap
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));
    
    // Linking first and second nodes
    head->data = 23;
    head->prev = NULL;
    head->next = second;

    // Linking second and third nodes
    second->data = 34;
    second->prev = head;
    second->next = third;

    // Linking third and fourth nodes
    third->data = 56;
    third->prev = second;
    third->next = fourth;

    // Terminate doubly linked list at the fourth node
    fourth->data = 52;
    fourth->prev = third;
    fourth->next = NULL;

    // traverse(head);
    head = reverse(head);
    traverse(head);
    
    return 0;
}