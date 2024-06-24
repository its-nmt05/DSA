#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

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

    traverse(head);

    return 0;
}