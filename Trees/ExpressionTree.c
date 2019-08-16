/*************************************************
Program to create an EXPRESSION TREE(using stacks)
*************************************************/
#include<stdio.h>
#include<stdlib.h>
#define SIZE 50

char postfix[SIZE];
int top = -1;
struct node * Stack[SIZE];

struct node
          {
              int info;
              struct node *left;
              struct node *right;
          };

struct node* CreateNode(char elem)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->info = elem;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void push(struct node *T)
{
    if(top == SIZE-1)
        printf("The stack is FULL");
    else
    {
        Stack[++top] = T;
    }
    return;
}

struct node * pop()
{
    if(top == -1)
    {
        printf("The stack is empty\n");
        return;
    }
    else
        return Stack[top--];
}

void inorder(struct node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%2c", root->info);
        inorder(root->right);
    }
    return;
}

int main()
{
    int i;
    struct node *temp;
    printf("Enter the postfix expression : ");
    scanf("%s",postfix);

    for(i=0; postfix[i]!= '\0'; i++)
    {
        temp = CreateNode(postfix[i]);
        if(((postfix[i] >= 'a')&&(postfix[i] <= 'z'))||((postfix[i] >= 'A')&&(postfix[i] <= 'Z')))
        {
            push(temp);
        }
        else
        {
            struct node *popped1 = pop();
            struct node *popped2 = pop();
            temp->right = popped1;
            temp->left = popped2;
            push(temp);
        }
    }
    inorder(temp);
    return 0;
}





