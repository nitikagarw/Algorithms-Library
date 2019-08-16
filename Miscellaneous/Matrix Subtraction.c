/*******************************************
Program to find the subtraction of two matrices
*******************************************/

#include<stdio.h>

int main()
{
    int a[10][10] , b[10][10] , c[10][10] ;
    int i, j , m , n , p, q;
    printf("Enter the no. of rows &columns of first matrix: ");
    scanf("%d%d" , &m , &n );
    printf("Enter the no. of rows & columns of 2nd matrix : ");
    scanf("%d%d" , &p , &q );

    if( (m!=p) || (n!=q) )
    printf("Sorry , subtraction wont be possible...!!!\n") ;

    else
   {

    printf("Enter the elements of first matrix \n");
    for( i=0 ; i<m ; i++)
    {
        for( j=0 ; j<n ; j++ )
        scanf( "%d" , &a[i][j] ) ;
    }

     printf("Enter the elements of second matrix \n");
    for( i=0 ; i<p; i++)
    {
        for( j=0 ; j<q ; j++ )
        scanf( "%d" , &b[i][j] ) ;
    }

     for( i=0 ; i<m ; i++) // to calculate sum
    {
        for( j=0 ; j<n ; j++ )
        c[i][j] = a[i][j] - b[i][j] ;
    }

    printf("The required matrix is \n") ;

     for( i=0 ; i<m ; i++)
    {
        for( j=0 ; j<n ; j++ )
        printf("%2d  " , c[i][j]) ;
        printf("\n");
    }
   }
    return 0 ;
}
