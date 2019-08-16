//Program to reverse a sorted singly linked list
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;

};
struct llist
{
    struct node *header;
    int list_size;
};
struct llist my_list;

void initialize(struct llist *listptr);
//void create(struct llist *listptr);
void insertL(struct llist *listptr,int elem);
void reverse_list(struct llist *listptr);
void display(struct llist *listptr);

int main()
{
    int ch, a ;
    char choice;
    initialize(&my_list);
    do
    {
        printf("Main menu:\n");
        printf("1 Insert an Element\n");
        printf("2 Reverse a list\n");
        printf("Enter your choice : ");
        scanf("%d" , &ch);
        printf("\n");
        switch(ch)
        {
            case 1 : printf("Enter the value you want to insert : ");
                     scanf("%d" , &a);
                     insertL(&my_list , a);
                     display(&my_list);
                     break;
            case 2 : reverse_list(&my_list);
                     printf("\nThe linked list has been reversed..!!\n");
                     display(&my_list);
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

void initialize(struct llist *listptr)
{
    listptr->header=NULL;
    listptr->list_size=0;
}

/*void create(struct llist *listptr)
{
    int n , k;

    printf("Enter the no. of elements u want to enter\n");
    scanf("%d", &n);
    for(k=0 ; k<n ; k++)
    {
        if(k==0)
        {
            listptr->header=(struct node*)malloc(sizeof(struct node));
            p=listptr->header;
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
*/

void insertL(struct llist *listptr,int elem)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=elem;
    newnode->next=NULL;
    if(listptr->header==NULL)
    {
        listptr->header=newnode;
    }
    else
    {
        struct node *newheader;
        newheader=listptr->header;
        while(newheader->next!=NULL)
        {
            newheader=newheader->next;
        }
        newheader->next=newnode;
    }
    listptr->list_size += 1;
    printf("Element : %d successfully inserted\n",newnode->data);
}

void reverse_list(struct llist *listptr)
{
    struct node *h1 , *h2 , *h3 ;
    h1 = listptr->header;
    h2 = h1->next;
    h3 = h2->next;
    h1->next = NULL ;

    while(h3!=NULL)
    {
        h2->next = h1 ;
        h1 = h2;
        h2 = h3 ;
        h3 = h3->next;
    }
    h2->next = h1;
    listptr->header = h2;
    return;
}

void display(struct llist *listptr)
{
    struct node *newheader;
    newheader=listptr->header;
    if(listptr->list_size==0)
    {
        printf("list is empty\n");
        return;
    }
    else
    {
        printf("The linked list is now : \n");
        while(newheader->next!=NULL)
        {
            printf("%d -> ",newheader->data);
            newheader=newheader->next;
        }
        printf("%d ",newheader->data);
    }
}

