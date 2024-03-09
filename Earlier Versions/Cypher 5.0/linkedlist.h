// CYPHER PROGRAM
// GENERIC LINKLIST HEADER FILE

/* linkedlist.h */
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#define MAX_LEN 53 // 52 characters + 1 for null terminator

// Node structure for the linked list
struct Node {
    char data[MAX_LEN];
    struct Node* next;
};

// Function prototypes
struct Node* createNode(char* data);
void insertNode(struct Node** head, char* data);
void displayList(struct Node* head);
void freeList(struct Node* head);

#endif