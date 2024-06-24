#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertAtFirst(struct Node* head, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    
    struct Node* p = head;
    do {
        p = p->next;
    } while(p->next != head);

    // At this point p points to the last node of the list
    p->next = ptr;
    ptr->next = head;
    head = ptr;

    return head;
}

void traverse(struct Node* head) {
    struct Node* ptr = head;
    
    do {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while(ptr != head);
} 

int main() {
    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;
    
    // Allocate memory for nodes in linked-list in heap
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));

    // Link first and second notes
    head->data = 4;
    head->next = second;

    // Link second and third nodes
    second->data = 3;
    second->next = third;

    // Link third and fourth nodes
    third->data = 8;
    third->next = fourth;
    
    // Terminate the list at the fourth node
    fourth->data = 1;
    fourth->next = head;

    // traverse(head);
    head = insertAtFirst(head, 20);
    head = insertAtFirst(head, 21);
    head = insertAtFirst(head, 22);
    traverse(head);
    
    return 0;
}