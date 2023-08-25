#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL, *newnode, *temp;
    int choice;

    while (1) {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
            temp = head;
        } else {
            newnode->next = head;
            head = newnode;
        }

        printf("Do you want to continue (0, 1)? ");
        scanf("%d", &choice);
        if (choice != 1) {
            break;
        }
    }

    // Print the linked list
    printf("Original Linked List:\n");
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    // Insert data at a specific position
    int position;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data to insert: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    printf("Enter position to insert: ");
    scanf("%d", &position);

    if (position <= 1) {
        newnode->next = head;
        head = newnode;
    } else {
        temp = head;
        for (int i = 1; i < position - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp != NULL) {
            newnode->next = temp->next;
            temp->next = newnode;
        } else {
            printf("Invalid position.\n");
            free(newnode);
        }
    }

    // Print the updated linked list
    printf("Updated Linked List:\n");
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    // Free the allocated memory
    temp = head;
    while (temp != NULL) {
        struct node *nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }

    return 0;
}
