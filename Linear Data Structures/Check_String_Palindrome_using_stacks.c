//Program to check whether a given string is palindrome or not using stacks

#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#define SIZE 50

int top = -1;
char Stack[SIZE] ,String[SIZE] , Reverse[SIZE] ;

void push(char ch);
char pop();

int main()
{

    int i , j;
    printf("\nEnter the string : ");
    gets(String);

    for(i = 0 ; String[i]!='\0' ; i++)
    {
        push(String[i]);
    }

    for(j = 0 ; top!= -1 ; j++)
    {
        Reverse[j] = pop();
    }
    Reverse[j]='\0';

    printf("\nThe reversed string is : ");
    puts(Reverse);

    for(i=0 , j=0 ; String[i]!='\0' , Reverse[j]!='\0' ; i++,j++)
    {
        if(String[i]!=Reverse[j])
        {
            printf("\nThe string is not a palindrome...!!\n");
            exit(1);
        }

    }

    printf("\nThe string is a palindrome..!!\n");
    return 0;
}

void push(char ch)
{
    if(top == SIZE-1)
       printf("\nStack OVERFLOW..!!");

    else
    {
        top++;
        Stack[top] = ch ;
    }

    return ;
}

char pop()
{
    char ret;
    if(top!= -1)
    {
        ret = Stack[top];
        top--;
        return ret ;
    }

    else
    {
        printf("\nStack UNDERFLOW...!!");
        return ;
    }
}



