//Program to insert a node at the beginning , middle and at the end of singly linked list
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;

}ptr;
ptr *head , *p;
int a , X ;

void create();
void insert_beg();
void insert_middle();
void insert_end();
void display();

int main()
{
    int ch ;
    char choice;
    do
    {
        printf("Main menu:\n");
        printf("1 Create a list\n");
        printf("2 Insert at the beginning\n");
        printf("3 Insert in the middle\n");
        printf("4 Insert at the end\n");
        printf("Enter your choice\n");
        scanf("%d" , &ch);
        switch(ch)
        {
            case 1 : create();
                     break;
            case 2 : printf("Enter the value you want to insert : ");
                     scanf("%d" , &a);
                     insert_beg();
                     break;
            case 3 : printf("Enter the value you want to insert : ");
                     scanf("%d" , &a);
                     printf("Enter the value after which you want to insert :");
                     scanf("%d" , &X);
                     insert_middle();
                     break;
            case 4 : printf("Enter the value you want to insert : ");
                     scanf("%d" , &a);
                     insert_end();
                     break;
           default : printf("Wrong choice\n");
                     break;
        }
        printf("\nDo u want to continue..??\n");
        fflush(stdin);
        scanf("%c" , &choice);

    }while((choice=='y')||(choice=='Y'));

    display();
    return 0;
}

void create()
{
    int n , k;

    printf("Enter the no. of elements u want to enter\n");
    scanf("%d", &n);
    for(k=0 ; k<n ; k++)
    {
        if(k==0)
        {
            head=(struct node*)malloc(sizeof(struct node));
            p=head;
        }
         else
         {
             p->next = (struct node*)malloc(sizeof(struct node));
             p = p->next;
         }
          scanf("%d" , &(p->data));
    }
    p->next=NULL;
    return;
}

void insert_beg()
{
    ptr* tempcell;
    tempcell = (struct node*)malloc(sizeof(struct node));
    tempcell->data= a;
    tempcell->next = head ;
    head = tempcell;
    return ;
}

void insert_middle()
{
    ptr*tempcell;
    tempcell=(struct node*)malloc(sizeof(struct node));
    tempcell->data = a;
    ptr*tmphead = head;
    while(tmphead!=NULL&& tmphead->data!= X)
    {
        tmphead=tmphead->next;
    }
    tempcell->next=tmphead->next;
    tmphead->next=tempcell;
    return ;
}

void insert_end()
{
    ptr*tempcell;
    tempcell = (struct node*)malloc(sizeof(struct node));
    tempcell->data = a;
    tempcell->next = NULL;
    ptr*tmphead = head;
    while(tmphead!=NULL &&tmphead->next!=NULL)
    {
        tmphead=tmphead->next;
    }
    tmphead->next=tempcell;
    return;
}

void display()
{
    ptr*tmphead=head;
    printf("\nThe linked list so formed is :   \n\n");
    while(tmphead->next!=NULL)
    {
        printf("%d --> " , tmphead->data);
        tmphead = tmphead->next;
    }
    printf("%d\n\n" , tmphead->data);
    return;
}




