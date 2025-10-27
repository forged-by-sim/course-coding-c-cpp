#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Create a new node
Node* create_node(int value) {
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->data = value;
    temp->next = NULL;
    return temp;
}

// Insert at the end
void append(Node **head, int value) {
    Node *new_node = create_node(value), *last = *head;
    if (!*head) {
        *head = new_node;
        return;
    }
    while (last->next)
        last = last->next;
    last->next = new_node;
}

// Bubble sort on linked list
void bubble_sort(Node *head) {
    int swapped;
    Node *ptr1;
    Node *lptr = NULL;
    if (!head)
        return;
    do {
        swapped = 0;
        ptr1 = head;
        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                int tmp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = tmp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// Print the list in rows of 5
void print_list(Node *head) {
    int count = 0;
    while (head) {
        printf("%4d", head->data);
        count++;
        if (count % 5 == 0)
            printf("\n");
        head = head->next;
    }
    if (count % 5 != 0)
        printf("\n");
}

// Free the list
void free_list(Node *head) {
    Node *temp;
    while(head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node *head = NULL;
    srand(time(NULL));
    for (int i = 0; i < N; i++)
        append(&head, rand() % 1000); // random numbers (0–999)

    printf("Original list:\n");
    print_list(head);

    bubble_sort(head);

    printf("\nSorted list:\n");
    print_list(head);

    free_list(head);
    return 0;
}
