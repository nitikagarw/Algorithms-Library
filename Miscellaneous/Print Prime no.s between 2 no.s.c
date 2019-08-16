//Program to print prime numbers between two given numbers
#include<stdio.h>
int prime( int );
int main()
{
    int a , b  , i;
    printf("Enter the numbers : ");
    scanf("%d%d" , &a , &b);

    printf("The prime numbers are : \n");
    for(i=a+1 ; i<b ; i++)
    {
        int r= 0;
        r= prime(i);
         if(r==1)
         printf("%4d\n" , i);
    }
    printf("\n");
    return 0;
}

int prime( int p)
{
    int k;
    if(p==1)
    return 1;

    else
    {
        for(k=2 ; k<(p/2) ; k++)
        {
            if(p%k == 0)
            return 0;
        }
        return 1;
    }

}
