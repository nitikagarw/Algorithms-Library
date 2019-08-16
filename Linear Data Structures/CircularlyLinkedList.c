/*************************************************************************
Program to count the number of nodes
           print the contents
           insert a node at the beginning
           insert a node at the end
           delete the first node
           delete the last node            in a circularly linked list
*************************************************************************/
#include<stdio.h>
#include<stdlib.h>

typedef struct node
    {
       int data;
       struct node *next;

    }ptr;
ptr *head , *p;
int a ;

void create();
void count_node();
void delete_beg();
void delete_end();
void insert_beg();
void insert_end();
void display();

int main()
{
    int ch ;
    char choice;
    do
    {
        printf("Main menu:\n");
        printf("  1 Create a list\n");
        printf("  2 Insert at the beginning\n");
        printf("  3 Insert at the end\n");
        printf("  4 Delete the first node\n");
        printf("  5 Delete the last node\n");
        printf("  6 Display the elements of the list\n");
        printf("  7 Count the number of nodes\n");
        printf("\n Enter your choice  : ");
        scanf("%d" , &ch);
        printf("\n");
        switch(ch)
        {
            case 1 : create();
                     break;
            case 2 : printf("Enter the element you want to insert :");
                     scanf("%d" , &a);
                     insert_beg();
                     printf("Element inserted..!!\n");
                     break;
            case 3 : printf("Enter the element you want to insert :");
                     scanf("%d" , &a);
                     insert_end();
                     printf("Element inserted..!!\n");
                     break;
            case 4 : delete_beg();
                     printf("Element deleted..!!\n");
                     break;
            case 5 : delete_end();
                     printf("Element deleted..!!\n");
                     break;
            case 6 : display();
                     break;
            case 7 : count_node();
                     break;
           default : printf("Wrong choice\n");
                     break;
        }
        printf("\nDo you want to continue(Y/N)..??  : ");
        fflush(stdin);
        scanf("%c" , &choice);
        printf("\n");

    }while((choice=='y')||(choice=='Y'));

    return 0;
}

void create()
{
    int n , k;

    printf("Enter the no. of elements you want to enter : ");
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
    p->next=head;
    return;

}

void insert_beg()
{
    ptr *tempnode = (struct node*)malloc(sizeof(struct node));
    tempnode->data = a;
    tempnode->next = head ;
    p->next = tempnode ;
    head = tempnode;
    return;
}

void insert_end()
{
     ptr *tempnode = (struct node*)malloc(sizeof(struct node));
    tempnode->data = a;
    tempnode->next = p->next ;
    p->next = tempnode ;
    p = tempnode;
    return;
}

void delete_beg()
{
    ptr *tempnode = head ;
    p->next = head->next;
    head = head->next;
    tempnode->next = NULL ;
    free(tempnode);
    return ;
}

void delete_end()
{
    ptr *temphead = head;
    ptr *tempnode;
    while(temphead->next->next!=head)
    {
        temphead = temphead->next;
    }

    tempnode = temphead->next;
    temphead->next = head;
    tempnode->next = NULL ;
    free(tempnode);
    return;
}

void count_node()
{
    ptr *temphead = head;
    int count= 0;
    while(temphead->next!= head)
    {
        count++ ;
        temphead = temphead->next;

    }
    count++;
    printf("The number of nodes in the linked list are : %d\n" , count);

}

void display()
{
    ptr *temphead = head;
    printf("\n The linked list so formed is : \n\n");
    while(temphead->next!= head)
    {
        printf("%d ---> ",temphead->data);
        temphead = temphead->next;
    }
    printf("%d " , temphead->data);
   // printf("--> %d" , head->data);
    return;

}







