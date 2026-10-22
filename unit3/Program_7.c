#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev, *next;
};

int main() {
    struct node *head = NULL, *temp, *newnode;
    int n, i, key, val, ch;

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

    printf("Enter specific node: ");
    scanf("%d", &key);
    printf("Enter new value: ");
    scanf("%d", &val);
    printf("1. After  2. Before: ");
    scanf("%d", &ch);

    temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL)
        printf("Node not found");
    else {
        newnode = malloc(sizeof(struct node));
        newnode->data = val;

        if (ch == 1) {
            newnode->prev = temp;
            newnode->next = temp->next;

            if (temp->next != NULL)
                temp->next->prev = newnode;

            temp->next = newnode;
        } else {
            newnode->next = temp;
            newnode->prev = temp->prev;

            if (temp->prev != NULL)
                temp->prev->next = newnode;
            else
                head = newnode;

            temp->prev = newnode;
        }
    }

    for (temp = head; temp != NULL; temp = temp->next)
        printf("%d ", temp->data);

    return 0;
}