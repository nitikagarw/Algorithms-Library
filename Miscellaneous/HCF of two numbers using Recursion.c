//Program to calculate the HCF of two numbers using recursion
#include<stdio.h>
int HCF(int x , int y );
int main()
{
    int a , b , result;
    printf("Enter the numbers a , b (a>b) : ");
    scanf("%d%d" , &a , &b);
    result= HCF(a , b);
    printf("The HCF is : %d\n" , result);
    return 0;
}

int HCF(int x , int y)
{
    if((x%y)==0)
    return y;
    else
    return HCF(y , x%y);
}

