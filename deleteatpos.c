#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

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

    // Delete item from a specific position
    int position;
    printf("Enter position to delete: ");
    scanf("%d", &position);

    if (position == 1 && head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    } else if (position > 1 && head != NULL) {
        struct node *prev = NULL;
        temp = head;
        for (int i = 1; i < position && temp != NULL; i++) {
            prev = temp;
            temp = temp->next;
        }
        if (temp != NULL) {
            prev->next = temp->next;
            free(temp);
        }
    }

    // Print the updated list
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
