#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int getLinkedListLength(struct node *head) {
    int length = 0;
    struct node *temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    return length;
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

    // Calculate and print the length of the linked list
    int length = getLinkedListLength(head);
    printf("Length of the linked list: %d\n", length);

    // Rest of your code to delete nodes and print the list

    return 0;
}
