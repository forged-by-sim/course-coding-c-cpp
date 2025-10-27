#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 200
#define RANGE 50

// Doubly Linked List Node
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Append node at the end
void append(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Print the list
void printList(Node* head) {
    int count = 0;
    while (head != NULL) {
        printf("%3d ", head->data);
        head = head->next;
        count++;
        if (count % 20 == 0) printf("\n");
    }
    printf("\n");
}

// Bubble sort the list by data value
void bubbleSort(Node* head) {
    if (!head) return;

    int swapped;
    Node* ptr1;
    Node* lptr = NULL;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// Remove duplicates from sorted list
void removeDuplicates(Node* head) {
    if (!head) return;

    Node* current = head;
    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            Node* duplicate = current->next;
            current->next = duplicate->next;

            if (duplicate->next)
                duplicate->next->prev = current;

            free(duplicate);
        } else {
            current = current->next;
        }
    }
}

// Free memory
void freeList(Node* head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

// Main
int main() {
    Node* head = NULL;
    srand(time(NULL));

    // Create 200 random elements
    for (int i = 0; i < SIZE; i++) {
        int num = rand() % RANGE;
        append(&head, num);
    }

    printf("Original List (200 elements, random [0–49]):\n");
    printList(head);

    bubbleSort(head);
    printf("\nSorted List:\n");
    printList(head);

    removeDuplicates(head);
    printf("\nList after removing duplicates:\n");
    printList(head);

    freeList(head);
    return 0;
}
