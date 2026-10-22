#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev, *next;
};

int main() {
    struct node *head = NULL, *temp, *newnode;
    int n, i, ch, key;

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

    printf("1. First  2. Last  3. Specific: ");
    scanf("%d", &ch);

    if (ch == 3) {
        printf("Enter value to delete: ");
        scanf("%d", &key);
    }

    temp = head;

    if (ch == 1 && head != NULL) {
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        free(temp);
    } else if (ch == 2 && head != NULL) {
        while (temp->next != NULL)
            temp = temp->next;

        if (temp->prev != NULL)
            temp->prev->next = NULL;
        else
            head = NULL;

        free(temp);
    } else if (ch == 3) {
        while (temp != NULL && temp->data != key)
            temp = temp->next;

        if (temp == NULL)
            printf("Node not found\n");
        else {
            if (temp->prev != NULL)
                temp->prev->next = temp->next;
            else
                head = temp->next;

            if (temp->next != NULL)
                temp->next->prev = temp->prev;

            free(temp);
        }
    }

    for (temp = head; temp != NULL; temp = temp->next)
        printf("%d ", temp->data);

    return 0;
}