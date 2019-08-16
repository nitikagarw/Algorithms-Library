//Program to insert a node in the beginning , in the middle and in the end in a doubly linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;

}ptr;
ptr *head, *p;
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
        printf("2 Insert in the beginning\n");
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
                     printf("Eter the value after which you want to insert : ");
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
        printf("\n");

    }while((choice=='y')||(choice=='Y'));

    display();
    return 0;
}
void create()
{
    int n , k;

    printf("Enter the no. of elements u want to enter : ");
    scanf("%d", &n);
    for(k=0 ; k<n ; k++)
    {
        if(k==0)
        {
            head=(struct node*)malloc(sizeof(struct node));
            p=head;
            p->prev = NULL ;
        }
         else
         {
             p->next = (struct node*)malloc(sizeof(struct node));
             p->next->prev=p;
             p = p->next;
         }
          scanf("%d" , &(p->data));
    }
    p->next=NULL;
    return;
}

void insert_beg()
{
    ptr *tempnode = (struct node *)malloc(sizeof(struct node));
    tempnode->data = a;
    tempnode->prev = NULL ;
    tempnode->next = head;
    head->prev = tempnode;
    head= tempnode;
    return;
}

void insert_middle()
{
    ptr*tempnode;
    tempnode=(struct node*)malloc(sizeof(struct node));
    tempnode->data = a;
    ptr*temphead = head;
    while(temphead!=NULL&& temphead->data!= X)
    {
        temphead=temphead->next;
    }
    tempnode->next=temphead->next;
    temphead->next->prev=tempnode;
    temphead->next=tempnode;
    tempnode->prev = temphead;
    return ;
}

void insert_end()
{
    ptr *tempnode=(struct node *)malloc(sizeof(struct node));
    tempnode->data = a;
    tempnode->next=NULL;
    ptr *temphead = head;
     while(temphead!=NULL &&temphead->next!=NULL)
    {
        temphead=temphead->next;
    }
    temphead->next=tempnode;
    tempnode->prev = temphead;
    return;
}

void display()
{
     ptr*temphead=head;
    printf("\nThe linked list so formed is :   \n\n");
    while(temphead->next!=NULL)
    {
        printf("%d --> " , temphead->data);
        temphead = temphead->next;
    }
    printf("%d\n\n" , temphead->data);
    return;
}








