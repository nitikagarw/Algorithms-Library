//Program to delete the first node , last node and intermediate node from a doubly linked list

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node*prev;

}ptr;
ptr *head , *p;
int a , X ;

void create();
void delete_beg();
void delete_middle();
void delete_end();
void display();

int main()
{
    int ch ;
    char choice;
    do
    {
        printf("Main menu:\n");
        printf("1 Create a list\n");
        printf("2 Delete the first node\n");
        printf("3 Delete an intermediate node\n");
        printf("4 Delete the last node\n");
        printf("Enter your choice\n");
        scanf("%d" , &ch);
        switch(ch)
        {
            case 1 : create();
                     break;
            case 2 : delete_beg();
                     break;
            case 3 : printf("Enter the value you want to delete : ");
                     scanf("%d" , &X);
                     delete_middle();
                     break;
            case 4 : delete_end();
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

void delete_beg()
{
    ptr *tempnode=head;
    head = head->next;
    tempnode->next = NULL;
    head->prev = NULL;
    free(tempnode);
    return;

}

void delete_middle()
{
    ptr*tempnode;
    ptr*temphead = head;
    while(temphead->next!=NULL&& temphead->next->data!= X)
    {
        temphead=temphead->next;
    }
    tempnode = temphead->next;
    temphead->next =temphead->next->next;
    temphead->next->prev=temphead;
    tempnode->next=NULL;
    tempnode->prev = NULL;
    free(tempnode);
    return ;
}

void delete_end()
{
    ptr*tempnode;
    ptr*temphead = head;
    while(temphead!=NULL &&temphead->next->next!=NULL)
    {
        temphead=temphead->next;
    }
    tempnode = temphead->next;
    temphead->next = NULL;
    tempnode->prev = NULL;
    free(tempnode);
    return;
}

void display()
{
    ptr*tmphead=head;
    printf("\nThe linked list after deletion is :   \n\n");
    while(tmphead->next!=NULL)
    {
        printf("%d --> " , tmphead->data);
        tmphead = tmphead->next;
    }
    printf("%d\n\n" , tmphead->data);
    return;
}

