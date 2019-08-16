//Program to print Floyd's Triangle
#include<stdio.h>
int main()
{
    int n , i , a=1 , j;
    printf("Enter the number of rows : ");
    scanf("%d" , &n);

    for(i=0 ; i<n ; i++)
    {
        for(j=0 ; j<=i ; j++)
        {
            printf("%2d  " , a);
            a++;
        }
        printf("\n");

    }
    return 0;

}
