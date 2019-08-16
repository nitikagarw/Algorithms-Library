/***********************************************
Program to find the multiplication of digits of any integer
***********************************************/
#include<stdio.h>
int main()
{

    int num , digit , product = 1 ;

    printf( " Enter the number : ");
    scanf("%d" , &num );

    do
    {
        digit =  num%10 ;
        product*= digit ;
        num = num/10 ;

    } while( num!= 0 );

    printf(" The multiplication of digits of the number is : %d\n" , product );
    return 0 ;

}
