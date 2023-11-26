// CYPHER PROGRAM
// GENERIC LINKEDLIST PROGRAM FOR FUTURE USE

/* linkedlist.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"


// Function to create a new node
struct Node* createNode(char* data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    strncpy(newNode->data, data, MAX_LEN - 1);
    newNode->data[MAX_LEN - 1] = '\0'; // Ensure null termination
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertNode(struct Node** head, char* data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to display the linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("Linked List:\n");
    while (head != NULL) {
        printf("%s\n", head->data);
        head = head->next;
    }
}

// Function to free memory allocated to the linked list
void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}