//Program to implement operations on a stack

#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

struct stacks{
               int elem[SIZE];
               int top;
             }st;

void initialise();
int push(int data);
int pop();
char isempty();
int sizeofst();
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
        printf("1 Push an element in the stack\n");
        printf("2 Pop an element from the stack\n");
        printf("3 Calculate the size of the stack\n");
        printf("4 Check if the stack is empty\n");
        printf("Enter your choice : ");
        scanf("%d" , &ch);
        printf("\n");
        switch(ch)
        {
            case 1 : printf("Enter the value you want to insert : ");
                     scanf("%d" , &a);
                     b=push(a);
                     if(b == 0)
                        printf("The element successfully inserted..\n");
                     else if(b== -1)
                        printf("Stack Overflow\n");
                     display();
                     break;
            case 2 : a= pop();
                     if(a == -1)
                        printf("Stack Underflow\n");
                     else
                        printf("THe element popped is %d\n" , a);
                     display();
                     break;
            case 3 : a = sizeofst();
                     printf("The size of the stack is %d\n", a);
                     break;
            case 4 : z = isempty();
                     if(z== 'y')
                        printf("The stack is empty\n");
                     else if(z == 'n')
                     {
                         printf("The stack is not empty\n");
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
    st.top = -1;
}

int push(int data)
{
    if(st.top == SIZE-1)
        return -1;
    else
    {
        st.top++;
        st.elem[st.top] = data;
        return 0 ;
    }
}

int pop()
{
    int x;
    if(st.top == -1)
        return -1;
    else
    {
        x = st.elem[st.top];
        st.top-- ;
        return x ;
    }
}

char isempty()
{
    if(st.top == -1)
        return 'y';
    else
        return 'n';
}

int sizeofst()
{
    return(st.top + 1);
}

void display()
{
    int i,c ;
    c=sizeofst();
    if(c==0)
        printf("The stack is empty\n");
    else
    {
        printf("The stack is now : \n");
        for(i=0 ; i<c ; i++)
        {
            printf("%d " , st.elem[i]);
        }
    }
    return;
}




