#include<stdio.h>
#include<string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch)
{
    if(top == MAX-1)
    {
        printf("\nStack Overflow");
    }
    else
    {
        top++;
        stack[top] = ch;
    }
}

char pop()
{
    if(top == -1)
    {
        return '\0';
    }
    else
    {
        return stack[top--];
    }
}

void main()
{
    char str[MAX];
    int i;

    printf("Enter a string: ");
    gets(str);

    for(i = 0; str[i] != '\0'; i++)
    {
        push(str[i]);
    }

    printf("\nReversed String: ");

    while(top != -1)
    {
        printf("%c", pop());
    }

}
write a program to display the top element if the stacj without removing it
