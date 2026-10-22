#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL, *temp, *newnode, *prev;
    int n, i, key, val, ch;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        newnode = malloc(sizeof(struct node));
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL)
            head = temp = newnode;
        else {
            temp->next = newnode;
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
    prev = NULL;

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        printf("Node not found");
    else {
        newnode = malloc(sizeof(struct node));
        newnode->data = val;

        if (ch == 1) {
            newnode->next = temp->next;
            temp->next = newnode;
        } else {
            newnode->next = temp;
            if (prev == NULL)
                head = newnode;
            else
                prev->next = newnode;
        }
    }

    for (temp = head; temp != NULL; temp = temp->next)
        printf("%d ", temp->data);

    return 0;
}