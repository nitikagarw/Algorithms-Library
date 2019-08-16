//Program to calculate the power of a number using recursion
#include<stdio.h>
int power(int x , int y );
int main()
{
    int n , p , result;
    printf("Enter the number and the power : ");
    scanf("%d%d" , &n , &p);
    result= power(n , p);
    printf("The result is : %d\n" , result);
    return 0;
}

int power(int x , int y)
{
    if(y==1)
    return x;
    else
    return (x*power(x , y-1));
}
