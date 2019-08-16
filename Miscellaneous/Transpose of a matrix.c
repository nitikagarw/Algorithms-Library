//Program to find the transpose of a matrix
#include<stdio.h>
int main()
{

    int m , n , i , j ;
    printf("Enter the rows and columns of a matrix : ");
    scanf("%d%d" , &m , &n);
    int a[m][n];

    for(i=0 ; i<m ; i++)
    {
        for(j=0 ; j<n ; j++)
        scanf("%d" , &a[i][j]);
        printf("\n");
    }
    printf("The original matrix is : \n");
    for(i=0 ; i<m ; i++)
    {
        for(j=0 ; j<n ; j++)
        printf("%3d " , a[i][j]);
        printf("\n");
    }
    printf("\n");

     printf("The transposed matrix is : \n");
    for(i=0 ; i<m ; i++)
    {
        for(j=0 ; j<n ; j++)
        printf("%3d ", a[j][i]);
        printf("\n");
    }

    return 0;


}
