#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold atomic element data
typedef struct Element {
    char name[20];
    char symbol[5];
    float atomicWeight;
    struct Element* next;
} Element;

// Function to create a new node
Element* createElement(const char* name, const char* symbol, float weight) {
    Element* newElement = (Element*)malloc(sizeof(Element));
    strcpy(newElement->name, name);
    strcpy(newElement->symbol, symbol);
    newElement->atomicWeight = weight;
    newElement->next = NULL;
    return newElement;
}

// Append to the end of the linked list
void appendElement(Element** head, const char* name, const char* symbol, float weight) {
    Element* newElement = createElement(name, symbol, weight);
    if (*head == NULL) {
        *head = newElement;
        return;
    }

    Element* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newElement;
}

// Print the list in a readable table
void printElements(Element* head) {
    printf("\n%-3s | %-10s | %-4s | %s\n", "No.", "Name", "Sym", "Atomic Weight");
    printf("-----------------------------------\n");

    int count = 1;
    while (head != NULL) {
        printf("%-3d | %-10s | %-4s | %.3f\n", count++, head->name, head->symbol, head->atomicWeight);
        head = head->next;
    }
}

// Free memory
void freeList(Element* head) {
    Element* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function
int main() {
    Element* head = NULL;

    // Pre-filled data for first 10 elements
    appendElement(&head, "Hydrogen",  "H",  1.008);
    appendElement(&head, "Helium",    "He", 4.003);
    appendElement(&head, "Lithium",   "Li", 6.941);
    appendElement(&head, "Beryllium", "Be", 9.012);
    appendElement(&head, "Boron",     "B",  10.811);
    appendElement(&head, "Carbon",    "C",  12.011);
    appendElement(&head, "Nitrogen",  "N",  14.007);
    appendElement(&head, "Oxygen",    "O",  15.999);
    appendElement(&head, "Fluorine",  "F",  18.998);
    appendElement(&head, "Neon",      "Ne", 20.180);

    // Output
    printElements(head);

    // Clean up
    freeList(head);
    return 0;
}
