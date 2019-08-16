//Program to delete the first node , last node and intermediate node from a singly linked list

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

void delete_beg()
{
    ptr* tempcell;
    tempcell = head;
    head = head->next;
    tempcell->next = NULL;
    free(tempcell);
        return ;
}

void delete_middle()
{
    ptr*tempcell;
    ptr*tmphead = head;
    while(tmphead->next!=NULL&& tmphead->next->data!= X)
    {
        tmphead=tmphead->next;
    }

    tempcell= tmphead->next;
    tmphead->next =tmphead->next->next;
    tempcell->next=NULL;
    free(tempcell);

    return ;
}

void delete_end()
{
    ptr*tempcell;
    ptr*tmphead = head;
    while(tmphead!=NULL &&tmphead->next->next!=NULL)
    {
        tmphead=tmphead->next;
    }
    tempcell = tmphead->next;
    tmphead->next = NULL;
    free(tempcell);
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





