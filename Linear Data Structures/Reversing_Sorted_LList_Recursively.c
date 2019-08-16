//Program to reverse a sorted singly linked list recursively
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;

}ptr;
ptr *head , *p;

void create();
void reverse_list();
void display();

int main()
{
    int ch ;
    char choice;
    do
    {
        printf("Main menu:\n");
        printf("1 Create a list\n");
        printf("2 Reverse a list\n");
        printf("Enter your choice\n");
        scanf("%d" , &ch);
        switch(ch)
        {
            case 1 : create();
                     break;
            case 2 : reverse_list();
                     printf("\nThe linked list has been reversed..!!\n");
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

void reverse_list()
{
    ptr *h1 , *h2 , *h3 ;
    h1 = head;
    h2 = h1->next;
    h3 = h2->next;
    h1->next = NULL ;

    if(h3==NULL)
        h2->next = h1;
    head = h2;
    return;

    else

    while(h3!=NULL)
    {
        h2->next = h1 ;
        h1 = h2;
        h2 = h3 ;
        h3 = h3->next;
    }

}

void display()
{
    ptr*tmphead=head;
    printf("\nThe linked list is now :   \n\n");
    while(tmphead->next!=NULL)
    {
        printf("%d --> " , tmphead->data);
        tmphead = tmphead->next;
    }
    printf("%d\n\n" , tmphead->data);
    return;
}


