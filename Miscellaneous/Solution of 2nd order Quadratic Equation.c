//Program to obtain the solution of second order of quadratic equation
#include<stdio.h>
#include<math.h>
int main()
{

    float a , b , c , root1=0 , root2=0 , delta=0 ;
    printf("Enter the a , b , c of ax^2 + bx + c : ");
    scanf("%d%d%d" , &a , &b , &c );
    if( !a )
    printf("a should not be zero ...!!") ;
    else
    {
        delta = (( b*b ) - ( 4*a*c )) ;
        if(delta > 0)
        {
            root1 = ( -b + sqrt(delta))/(2*a) ;
            root2 = ( -b - sqrt(delta))/(2*a) ;
            printf("The roots are real and distinct :\n") ;
            printf("Root 1 = %5.2f\nRoot2 = %5.2f\n" , root1 , root2 ) ;

        }

        else if(delta == 0)
        {
            root1 = -b/(2*a) ;
            root2 = -b/(2*a) ;
            printf("The roots are real and equal :\n") ;
            printf("Root 1 = %5.2f\nRoot2 = %5.2f\n" , root1 , root2 ) ;
        }

         else
         printf(" Roots are complex and imaginary\n");
    }
    return 0 ;
}
