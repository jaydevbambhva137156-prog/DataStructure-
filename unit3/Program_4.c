#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL, *temp, *newnode, *prev;
    int n, i, ch, key;

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

    printf("1.First 2.Last 3.Specific: ");
    scanf("%d", &ch);

    if (head == NULL) {
        printf("List is empty");
    } else if (ch == 1) {
        temp = head;
        head = head->next;
        free(temp);
    } else if (ch == 2) {
        temp = head;

        if (head->next == NULL)
            head = NULL;
        else {
            while (temp->next->next != NULL)
                temp = temp->next;

            free(temp->next);
            temp->next = NULL;
        }
    } else if (ch == 3) {
        printf("Enter value to delete: ");
        scanf("%d", &key);

        temp = head;
        prev = NULL;

        while (temp != NULL && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL)
            printf("Node not found\n");
        else {
            if (prev == NULL)
                head = temp->next;
            else
                prev->next = temp->next;

            free(temp);
        }
    }

    printf("Linked list: ");
    for (temp = head; temp != NULL; temp = temp->next)
        printf("%d ", temp->data);

    return 0;
}