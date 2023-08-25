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
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    // Insert data at the beginning
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter data to insert: ");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;

    // Print the updated linked list
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    // Free the allocated memory
    temp = head;
    while (temp != NULL) {
        struct node *nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }

    return 0;
}
