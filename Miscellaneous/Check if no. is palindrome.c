//Program to check whether the given number is palindrome or not
#include<stdio.h>
int main()
{
    int num , rev = 0 , digit , n;
    printf("Enter the number : ");
    scanf("%d" , &num);
    n=num;
    do
    {
        digit = num%10;
        rev=(rev*10)+digit;
        num =  num/10;
    }while(num!=0);

    if(n==rev)
    printf("The given number is palindrome.\n");
    else
    printf("Not a palindrome\n");
    return 0;
}
