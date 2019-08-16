/****************************************************************
Program to print moves in the Tower of Hanoi problem using 3 pegs
***************************************************************/

#include<stdio.h>
#include<conio.h>

void transferdisc( int, char, char );
void towershanoi( int, char , char, char );
void main()
{
    int a;
    printf("Enter the number of discs: ");
    scanf("%d",&a);
    printf("Tower of hanoi is\n");
    towershanoi(a,'A', 'B', 'C');
    getch();
}

void towershanoi( int n, char origin, char spare, char final)
{
    if(n>1)
    {
        towershanoi(n-1, origin, final, spare);
        transferdisc(n, origin , final);
        towershanoi(n-1, spare, origin, final);

    }
    else
        transferdisc(n, origin, final);
}

void transferdisc(int n, char originpole, char finalpole)
{
    printf("Move disc %d from ",n);
    switch(originpole)
    {
        case 'A':printf(" Origin pole to ");
        break;
        case 'B':printf(" Spare pole to ");
        break;
        case 'C':printf(" Final pole to ");
        break;

    }

    switch(finalpole)
    {
        case 'A':printf(" Origin pole\n");
        break;
        case 'B':printf(" Spare pole\n");
        break;
        case 'C':printf(" Final pole\n");
        break;

    }
}
