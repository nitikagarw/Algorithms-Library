//Program to add 2 complex numbers
#include<stdio.h>
typedef struct
{
    float real;
    float img;
}complex;

complex a, b , c;

complex add(complex a , complex b);
void display(complex c);

int main()
{
    printf("Enter the real & imaginary part of first complex no. :");
    scanf("%f%f" , &(a.real) , &(a.img));

   printf("Enter the real & imaginary part of second complex no. :");
    scanf("%f%f" , &(b.real) , &(b.img));

   c= add(a , b);
   display(c);
   return 0;
}



 complex add(complex a , complex b)
 {
     complex temp;
     temp.real=a.real + b.real;
     temp.img=a.img + b.img;
     return(temp);
 }

 void display(complex c)
{
    char s[3]="+i";
    if((c.img)<0)
    {
         s[0] = '-' ;
        c.img = -(c.img);
    }

    printf("The result is : %.3f %s %.3f\n", (c.real) , s , (c.img));
    return;
}


