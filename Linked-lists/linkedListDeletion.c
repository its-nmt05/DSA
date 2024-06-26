#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Case 1: Deleting the first element from the linked list 
struct Node* deleteFirstNode(struct Node* head) {
    struct Node* p = head;
    head = head->next;
    free(p);

    return head;
}

// Case 2: Deleting element at a given index from the linked list
struct Node* deleteAtIndex(struct Node* head, int index) {
    struct Node* p = head;
    struct Node* q = head->next;

    int i = 0;
    while (i != index - 1) {
        p = p->next;
        q = q->next;
        i++;
    }

    p->next = q->next;
    free(q);

    return head;
}

// Case 3: Deleting the last element of the linked list
struct Node* deleteAtEnd(struct Node* head) {
    struct Node* p = head;
    struct Node* q = head->next;

    while(q->next != NULL) {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);

    return head;
}


// Case 4: Deleting the element with a given value
struct Node* deleteAtValue(struct Node* head, int value) {
    struct Node* p = head;
    struct Node* q = head->next;

    while(q->data != value && q->next != NULL) {
        p = p->next;
        q = q->next;
    }

    if (q->data == value) {
        p-> next = q->next;
        free(q);
    }
    
    return head;
}

void traverse(struct Node* ptr) {
    while(ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
} 

int main() 
{
    struct Node* head;
    struct Node* second;
    struct Node* third;
    struct Node* fourth;
    
    // Allocate memory for nodes in linked-list in heap
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));

    // Link first and second nodes
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
    fourth->next = NULL;

    // traverse(head);
    // head = deleteFirstNode(head);
    // head = deleteAtIndex(head, 2);
    // head = deleteAtEnd(head);
    head = deleteAtValue(head, 3);
    traverse(head);

    return 0;
}