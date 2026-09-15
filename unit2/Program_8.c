#include <stdio.h>
#define max 5

int queue[max];
int front =-1;
int rear =-1;

void insert(int value)
{
    if (rear == max -1)
    {
        printf("Queue overflow! cannot insert %d\n", value);
    }else
    {
        if (front == -1) front = 0;
        rear++;
        queue[rear] = value;
        printf("%d inserted into queue.\n",value);
    }
}

void delete()
{
    if (front == -1 || front > rear)
    {
        printf("queue underflow! no element to delete.\n");
    }
    else
    {
        printf("%d delete from queue.\n",queue[front]);
        front++;
    }
}

void display()
{
    if(front == -1 || front> rear)
    {
        printf("queue is empty.\n");
    }else
    {
        int i;
        printf("queue element are: ");
        for(i = front;i <= rear;i++)
        {
          printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice, value;
    while (1)
    {
        printf("\nqueue operation menu:\n");
        printf("1. insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            printf("Enter Value To Insert :");
            scanf("%d",&value);
            insert(value);
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting Program.\n");
            return 0;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
}
