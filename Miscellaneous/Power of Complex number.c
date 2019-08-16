#include<stdio.h>
#include<math.h>
int main()
{
    int a , b ,n ;
    float mod , arg , arg1, mod1 ;
    printf("enter the real and imaginary part of complex no. :");
    scanf("%d%d" , &a , &b);

    printf("\n enter the power : ");
    scanf("%d" , &n ) ;

    mod = sqrt( ((a*a) + (b*b)) ) ;
    arg = atan2(b, a) ;

    mod1 = pow(mod, n);
    arg1 = (n * arg) ;
    printf("\n the new complex no. is : ");
    printf( "%f ( %f + i %f)\n" , mod1 , cos(arg1) , sin(arg1) );

    return 0 ;


}
