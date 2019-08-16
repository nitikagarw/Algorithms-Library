//Program to concatenate two strings
#include<stdio.h>
int main()
{
    char s1[50] , s2[50];
    int i , j;
    printf("Enter the two strings : ");
    gets(s1);
    gets(s2);

    for(i=0 ; s1[i]!='\0' ;i++);
    for(j=0 ; s2[j]!='\0' ; j++)
    {
        s1[i++]=s2[j];
    }
    s1[i]= '\0';
    printf("The concatenate dstring is : ");
    puts(s1);
    return 0;
}
