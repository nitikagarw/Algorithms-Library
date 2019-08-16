// Program to print pascal triangle

#include<stdio.h>

long fact(int n)
{
	int i;
	long res=1;
	for(i=1;i<=n;i++)
		res = res*i;
	return res;
}

int main()
{
	int n,i,j;
	printf("Enter the number of rows\n");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		for(j=0;j<(n-i-1);j++)
			printf(" ");
		for(j=0;j<=i;j++)
			printf("%ld ",fact(i)/(fact(j)*fact(i-j)));
		printf("\n");
	}
	return 0;
}
	

