#include <stdio.h>

int main()
{
    int a[10], i, n;

    printf("Enter 10 elements:\n");
    for(i = 0; i < 10; i++)
        scanf("%d", &a[i]);

    printf("Array: ");
    for(i = 0; i < 10; i++)
        printf("%d ", a[i]);

    printf("\nEnter element to search: ");
    scanf("%d", &n);

    for(i = 0; i < 10; i++)
    {
        if(a[i] == n)
        {
            printf("Element Found");
            return 0;
        }
    }

    printf("Element Not Found");

    return 0;
}
