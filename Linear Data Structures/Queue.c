//Program to perform operations on a QUEUE

#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

struct queues{
               int elem[SIZE];
               int head;
               int tail;
             }q;

void initialise();
int enqueue(int data);
int dequeue();
char isempty();
int sizeofq();
void display();
int a;

int main()
{
    int ch, b ;
    char choice , z;
    initialise();
    do
    {
        printf("Main menu:\n");
        printf("1 Enqueue\n");
        printf("2 Dequeue\n");
        printf("3 Calculate the size of queue\n");
        printf("4 Check if the queue is empty\n");
        printf("Enter your choice\n");
        scanf("%d" , &ch);
        switch(ch)
        {
            case 1 : printf("Enter the value you want to insert : ");
                     scanf("%d" , &a);
                     b=enqueue(a);
                     if(b == 0)
                        printf("The element successfully inserted..\n");
                     else if(b == -1)
                        printf("The element cannot be inserted\n");
                     display();
                     break;
            case 2 : a= dequeue();
                     if(a == -1)
                        printf("Queue is empty\n");
                     else
                        printf("THe element deleted is %d\n" , a);
                     display();
                     break;
            case 3 : a = sizeofq();
                     printf("The size of the queue is %d\n", a);
                     break;
            case 4 : z = isempty();
                     if(z== 'y')
                        printf("The queue is empty\n");
                     else if(z == 'n')
                     {
                         printf("The queue is not empty\n");
                         display();
                     }
                     break;
           default : printf("Wrong choice\n");
                     break;
        }
        printf("\nDo u want to continue(y/n)..??\n");
        fflush(stdin);
        scanf("%c" , &choice);

    }while((choice=='y')||(choice=='Y'));

    return 0;
}

void initialise()
{
    q.head = 0;
    q.tail = 0;
}

int enqueue(int data)
{
    if( data >0 || data == 0 && q.tail < SIZE)
    {
       q.elem[q.tail] = data;
       q.tail = q.tail + 1 ;
       return 0;
    }

    else
        return -1;
}

/*int dequeue()
{
    int x;
    if(q.head < q.tail)
    {
         x = q.elem[q.head];
         q.head++ ;
         return x ;
    }
    else
        return -1 ;
}
*/
int dequeue()
{
    int x , i;
    if(q.head < q.tail)
    {
         x = q.elem[0];
         for(i = 0 ; i <q.tail; i++)
             q.elem[i] = q.elem[i+1];
        q.tail-- ;
        return x ;
    }
    else
        return -1 ;
}



char isempty()
{
    if(q.head == q.tail)
        return 'y';
    else
        return 'n';
}

int sizeofq()
{
    int s = 0 ;
    s = q.tail - q.head ;
    return s ;
}

void display()
{
    int i,c ;
    c=sizeofq();
    if(c==0)
        printf("The queue is empty\n");
    else
    {
        printf("The queue is now : \n");
        for(i=0 ; i<c ; i++)
        {
            printf("%d " , q.elem[i]);
        }
    }
    return;
}








