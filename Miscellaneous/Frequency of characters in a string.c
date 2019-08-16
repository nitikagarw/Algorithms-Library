//Program to find the frequency of characters in a given string
#include<stdio.h>
int main()
{
    char s[100] , i;
    int count[26] = {0};
    printf("Enter the string : ");
    gets(s);
    for(i=0 ; s[i]!='\0' ; i++)
    {
        if(s[i]>='a' && s[i]<='z')  // considering characters frm a-z only
        count[s[i]-'a']++;
    }
    printf("The frequency of characters in the given string are :\n");
    for(i=0 ; i<26 ; i++)
    printf("%c --> %2d\n" , i+'a' , count[i]);
    return 0;
}
