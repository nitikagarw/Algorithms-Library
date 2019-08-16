/*******************************************************
Program to find the nth fibonacci number using recursion
*******************************************************/

#include<stdio.h>

long fibonacci( long n );

int main()
{
    long result , number ;
    printf( "Enter an integer : " );
    scanf( "%ld" , &number );

    result = fibonacci( number );

    printf(" \nfibonacci(%ld) is : %ld\n" , number , result );
    return 0 ;

}

long fibonacci( long n )
{
    if( n == 0 || n == 1 )
    return n ;

    else
    return fibonacci( n-1 ) + fibonacci( n-2 );
}
