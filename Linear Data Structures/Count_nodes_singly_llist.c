//Program to count the number of elements in the singly-linked list
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;

}ptr;

ptr *head , *p ;

void create();
int count();
void display();

int main()
{
    int ch , a;
    char choice;
    do
    {
        printf("Main menu:\n");
        printf("1 Create a list\n");
        printf("2 count the no. of elements\n");
        printf("Enter your choice\n");
        scanf("%d" , &ch);
        switch(ch)
        {
            case 1 : create();
                     break;
            case 2 : a =  count();
                     printf("The no. of elements are : %d" , a);
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

int count()
{
    int c=0;
    ptr *t;
    t=head;
    while(t!=NULL)
    {
       c++;
       t = t-> next;

    }
    return(c);

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
