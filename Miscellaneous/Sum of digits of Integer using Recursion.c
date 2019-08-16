/***************************************************************
Program to find the sum of digits of any integer using Recursion
***************************************************************/
#include<stdio.h>
#include<conio.h>

int sum(int a);
void main()
{
    int n,f;
    printf("enter an integer (digits<=7): ");
    scanf("%d",&n);
    f=sum(n);
    printf("\nsum of digits is %d",f);
    getch();
}

int sum(int a)
{  static int k=0;
    if(a==0)
        return k;
    else
    {
        k+=(a%10);
        return sum(a/10);
    }
}

