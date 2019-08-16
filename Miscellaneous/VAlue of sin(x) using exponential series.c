/***********************************************************
Program to find the value of sin(x) using exponential series
***********************************************************/
#include<stdio.h>
#include<math.h>
float fact( int number );

int main()
{

    float x , sine ;

    printf("Enter the value of x in radians :");
    scanf("%f" , &x );

    sine = (x) - (( pow(x,3))/ fact(3)) + (( pow(x,5))/ fact(5)) - (( pow(x,7))/ fact(7)) ;

    printf( " The value of sin(x) is : %.4f " , sine );
    return 0 ;
}

float fact( int number )
{

    if( number <= 1 )
       return 1;

    else
       return number*fact( number-1 );
}
