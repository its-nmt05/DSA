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

struct Node* insertAtIndex(struct Node* head, int index, int data) {
    // reserve space for new Node in heap and set the data
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node* p = head;
    struct Node* q = head->next;

    int i = 0;
    while(i != index - 1) {
        p = p->next;
        q = q->next;
        i++;
    }
    /*
    when we reach here, p points to node before
    */

   p->next = ptr;
   if (q != NULL) {
    q->prev = ptr;
   }
   
   ptr->prev = p;
   ptr->next = q;

   return head;
}

struct Node* deleteAtIndex(struct Node* head, int index) {
    struct Node* p = head;
    struct Node* q = p->next;

    int i = 0;
    while(i != index - 1) {
        p = p->next;
        q = q->next;
        i++;
    }
    /*
    when we reach here, p points to the node just before the one we need to delete, 
    and q points to the node we need to delete.
    */
    p->next = q->next;  // p->next must point to the node after q
    
    if (q->next != NULL) {
        q->next->prev = p;  // the node after q must have its prev as p 
    }
    free(q);
    return head;
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
    // head = reverse(head);
    // head = deleteAtIndex(head, 3);
    head = insertAtIndex(head, 4, 84);
    traverse(head);
    
    return 0;
}