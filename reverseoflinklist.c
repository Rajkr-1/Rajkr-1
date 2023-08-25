#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *reverseLinkedList(struct node *head) {
    struct node *prev = NULL;
    struct node *current = head;
    struct node *nextNode = NULL;

    while (current != NULL) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    return prev;
}

void printLinkedList(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct node *head, *newnode, *temp;
    head = NULL; // Initialize head to NULL
    int choice;

    while (1) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter details: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }

        printf("Do you want to continue (0, 1)? ");
        scanf("%d", &choice);

        if (choice != 1) {
            break;
        }
    }

    printf("Original linked list: ");
    printLinkedList(head);

    // Reverse the linked list
    head = reverseLinkedList(head);

    printf("Reversed linked list: ");
    printLinkedList(head);

    // Rest of your code

    return 0;
}
