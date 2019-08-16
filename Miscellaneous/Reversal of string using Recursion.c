//Program to print the reverse of a string using recursion
#include<stdio.h>
#include<string.h>
char c[1000];
void reverse( int , int );
int main()
{
    int l;
    printf("Enter the string : ");
    gets(c);
    l=strlen(c);
    reverse(0 , (l-1));
    printf("%s\n" , c);
    return 0;
}

void reverse( int i, int j )
{
    char temp;
    if(i>=j)
    return;
    else
    {
        temp=c[i];
    c[i]=c[j];
    c[j]=temp;

    reverse(i+1 , j-1);
    }

}
