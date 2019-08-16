//Program to print Armstrong number between 2 given numbers
#include<stdio.h>
#include<math.h>
int main()
{
    int a ,b, r , x, i , num ;
    printf("Enter the numbers : ");
    scanf("%d%d" , &a , &b);

    for(i=a+1 ; i<b ; i++)
    {
        num=i;
        x=0;
        do
        {
           r=num%10;
           x+= (pow(r,3));
           num/= 10;
        }while(num!=0);

        if(i==x)
        printf("%d\n" , i);
    }
    return 0;
}
