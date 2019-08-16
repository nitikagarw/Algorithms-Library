/***********************************************
Program to find the sum of digits of any integer
***********************************************/
#include<stdio.h>
int main()
{

    int num , digit , sum = 0 ;

    printf( " Enter the number : ");
    scanf("%d" , &num );

    do
    {
        digit =  num%10 ;
        sum+= digit ;
        num = num/10 ;

    } while( num!= 0 );

    printf(" The sum of digits of the number is : %d\n" , sum );
    return 0 ;

}
