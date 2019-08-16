//Program to find the sum of first n natural no.s using recursion
#include<stdio.h>
int sum(int);
int main()
{
    int n , s;
    printf("Enter the value of n : ");
    scanf("%d", &n);
    s=sum(n);
    printf("The sum is %d\n" , s);
    return 0;
}
int sum(int a)
{
    if(a==1)
      return 1;
    else
      return(a+sum(a-1));
}
