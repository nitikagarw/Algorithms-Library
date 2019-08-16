//Program to calculate the factorial of a number using recursion
#include<stdio.h>
int factorial(int x);
int main()
{
    int n , fact;
    printf("Enter the no. whose factorial you want to calculate : ");
    scanf("%d" , &n);
    fact=factorial(n);
    printf("The factorial of the number is : %d\n" , fact);
    return 0;
}

int factorial(int x)
{
    if(x==0 || x==1)
    return 1;
    else
    return (x*factorial(x-1));
}
