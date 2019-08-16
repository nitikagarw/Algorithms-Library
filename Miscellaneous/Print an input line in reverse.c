/*****************************************
Program to print an input line in reverse
*****************************************/
#include<stdio.h>
#include<conio.h>
#include<string.h>
char c[100];
void reverse(int, int);
void main()
{
    int x;

    printf("Enter a string: ");
    gets(c);
    printf("\n");
    reverse(0, (strlen(c)-1));
    getch();
}

void reverse( int i , int j)
{
    if(j<=i)
        printf("%s",c);
    else
    {
        char temp=c[i];
        c[i]=c[j];
        c[j]=temp;
        reverse(i+1, j-1);
    }
}

