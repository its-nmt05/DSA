#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Case 1
struct Node* insertAtFirst(struct Node* head, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

// Case 2
struct Node* insertAtIndex(struct Node* head, int index, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = head;
    
    int i = 0;
    while(i != index - 1) {
        p = p->next;
        i++;
    }

    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;

    return head;
}

// Case 3
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node* p = head;

    while(p->next != NULL) {
        p = p->next;
    }

    p->next = ptr;
    ptr->next = NULL;

    return head;
}

// Case 4
struct Node* insertAfterNode(struct Node* head, struct Node* prevNode, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head;
}

void traverse(struct Node* ptr) {
    while(ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
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
    head->data = 5;
    head->next = second;

    // Link second and third nodes
    second->data = 9;
    second->next = third;

    // Link third and fourth nodes
    third->data = 15;
    third->next = fourth;
    
    // Terminate the list at the fourth node
    fourth->data = 23;
    fourth->next = NULL;

    // traverse(head);
    // head = insertAtFirst(head, 43);
    // head = insertAtIndex(head, 2, 43);
    // head = insertAtEnd(head, 43);
    head = insertAfterNode(head, second, 83);
    traverse(head);

    return 0;
}