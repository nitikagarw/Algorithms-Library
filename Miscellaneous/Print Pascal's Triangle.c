//Program to print Pascal's Triangle
#include<stdio.h>
int factorial( int number );

int main()
{
    int n , i , j ,k;
    printf("Enter the number of rows : ");
    scanf("%d" , &n);

    for(i=0 ; i<n ; i++)
    {
        for(k=1 ; k<=(n-i-1); k++)
        printf(" ");


        for(j=0 ; j<=i ; j++)
        {
            printf("%d " , fact(i)/(fact(j)*fact(i-j)));
        }
        printf("\n");

    }
    return 0;

}

 int fact( int number )
{

   int result=1 , k;
   for(k= number ; k>0 ; k--)
   result*=k;
   return result;
}


