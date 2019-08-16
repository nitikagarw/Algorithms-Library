//Program to check whether a given number is an Armstrong number or not
#include<stdio.h>
#include<math.h>
int main()
{
    int num, n , x=0 , r;
    printf("Enter the number : ");
    scanf("%d" , &num);

    n = num;

    do
    {
        r=num%10;
        x+= pow( r , 3);
        num/= 10;

    }while(num!=0);

    if(n==x)
    printf("Is an armstrong number\n");
    else
    printf("Not an armstrong number\n");
    return 0;
}
