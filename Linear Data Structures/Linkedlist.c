//Program to implement INSERTION and DELETION in a linked list

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
void initialize(struct llist *listptr)
{
    listptr->header=NULL;
    listptr->list_size=0;
}
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

void deleteL(struct llist *listptr,int value)
{
    int flag=0;
    struct node *newheader,*previous;
    if(listptr->list_size==0)
    {
        printf("list is empty\n");
        return;
    }
    else
    {
        newheader=listptr->header;
        previous=newheader;
        if(newheader->data==value)  //when element to be deleted is the first element
        {
            listptr->header=newheader->next;
            listptr->list_size -= 1;
            printf("Element : %d deleted\n",value);
            flag=1;
        }
        else    //when element to be deleted is neither the first element nor the last element
        {
            while(newheader->next!=NULL)
            {
                if(newheader->data==value)
                {
                    previous->next=newheader->next;
                    newheader=newheader->next;
                    listptr->list_size -= 1;
                    printf("Element : %d deleted\n",value);
                    flag=1;
                }
                else
                {
                    previous=newheader;
                    newheader=newheader->next;
                }
            }   //when element to be deleted is the last element
            if(newheader->data==value)
            {
                previous->next=NULL;
                listptr->list_size -= 1;
                printf("%d deleted\n",value);
                flag=1;
            }
        }
    }
    if(flag==0)
        printf("No data was deleted. \n");
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

int main()
{
    int ch ,a;
    char choice;
    initialize(&my_list);
    do
    {
        printf("Main menu:\n");
        printf("1 Insert an element\n");
        printf("2 Delete an element\n");
        printf("3 Display the linked list\n");
        printf("4 Calculate the size of the linked list\n");
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
            case 2 : printf("Enter the value you want to delete : ");
                     scanf("%d" , &a);
                     deleteL(&my_list , a);
                     display(&my_list);
                     break;
            case 3 : display(&my_list);
                     break;
            case 4:  printf("Size of list : %d\n",my_list.list_size);
                     break;
           default : printf("Wrong choice\n");
                     break;
        }
        printf("\nDo u want to continue(y/n)..?? :");
        fflush(stdin);
        scanf("%c" , &choice);

    }while((choice=='y')||(choice=='Y'));

    return 0;
}


