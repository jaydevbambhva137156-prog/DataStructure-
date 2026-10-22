#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev, *next;
};

int main() {
    struct node *head = NULL, *temp, *newnode;
    int n, i, ch;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        newnode = malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->prev = newnode->next = NULL;

        if (head == NULL)
            head = temp = newnode;
        else {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
    }

    printf("1. Beginning  2. End: ");
    scanf("%d", &ch);

    newnode = malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d", &newnode->data);
    newnode->prev = newnode->next = NULL;

    if (ch == 1) {
        newnode->next = head;
        if (head != NULL)
            head->prev = newnode;
        head = newnode;
    } else if (ch == 2) {
        if (head == NULL)
            head = newnode;
        else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newnode;
            newnode->prev = temp;
        }
    }

    for (temp = head; temp != NULL; temp = temp->next)
        printf("%d ", temp->data);

    return 0;
}