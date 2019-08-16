/***************************************************
Program to find the greatset among the three numbers
***************************************************/
#include<stdio.h>
int main()
{

    int a , b , c , max ;
    printf("Enter three numbers : ") ;
    scanf( "%d%d%d" ,  &a , &b , &c );
    max = a ;
    if( b > max)
    max = b ;
    if( c > max )
    max = c ;
    printf( "The greatest among the three numbers is : %d  \n " ,  max );
    return 0 ;

}
