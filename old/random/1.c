#include <stdio.h>

void square(int a);

void main()
{
    int z = 5;

    printf("enter data1\n");
    printf("enter data1\n");
    square(10);
    printf("enter data1\n");
    square(15);
    printf("enter data1\n");
    printf("enter data1\n");
    printf("enter data1\n");
    square(14);
}

void square(int a)
{
    int z = 1;
    for (int i = 1; i <= a; i++)
    {
        z = z * i;
    }
    printf("%d", z);
}