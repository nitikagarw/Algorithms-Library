/********************************************************************
Program to print the Preorder Traversal of a Binary Tree Iteratively
*********************************************************************/
#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
struct node
          {
              int info;
              struct node *left;
              struct node *right;
          };

struct node *Queue[SIZE];
int F=0, R=0;
struct node *NodeStack[SIZE];
int top = -1;

struct node* CreateNode(int elem)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->info = elem;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

void Enqueue(struct node *T)
{
    if(R == SIZE)
    {
         printf("The Queue is full\n");
         return;
    }
    else
    {
         Queue[R++] = T;
         return;
    }
}

struct node* Dequeue()
{
    if(F == R)
    {
         printf("The Queue is empty\n");
         return;
    }
    else
        return Queue[F++];
}

int q_empty()
{
    if(F==R)
        return 1;
    else
        return 0;

}

void Push(struct node *N)
{
   if(top == SIZE-1)
        return -1;
    else
    {
        top++;
        NodeStack[top] = N;
        return 0 ;
    }
}

struct node* Pop()
{
    if(top == -1)
        return NULL;
    else
        return NodeStack[top--] ;
}

int isempty_s()
{
    if(top == -1)
        return 1;
    else
        return 0;
}

void preorder(struct node *root)
{
    if(root == NULL)
        return root;

    Push(root);
    while(!isempty_s())
    {
        struct node *temp = Pop();
        printf("%4d", temp->info);
        if(temp->right != NULL)
            Push(temp->right);
        if(temp->left)
            Push(temp->left);
    }
}

int main()
{
    int value;
    char ch = 'n';
    struct node *root, *newnode, *temp;
    printf("Enter the root : ");
    scanf("%d", &value);
    root = CreateNode(value);
    Enqueue(root);

    while(!q_empty())
    {
        temp = Dequeue();
        printf("Do you want to add any right child of %d (y/n)?\n", temp->info);
        fflush(stdin);
        scanf("%c", &ch);
        if((ch =='y')||(ch == 'Y'))
        {
            printf("Enter the information : ");
            scanf("%d", &value);
            newnode = CreateNode(value);
            Enqueue(newnode);
            temp->right = newnode;
        }
        printf("Do you want to add any left child of %d (y/n)?\n", temp->info);
        fflush(stdin);
        scanf("%c", &ch);
        if((ch =='y')||(ch == 'Y'))
        {
            printf("Enter the information : ");
            scanf("%d", &value);
            newnode = CreateNode(value);
            Enqueue(newnode);
            temp->left = newnode;
        }
    }
    printf("The tree is now : \n");
    preorder(root);
    return 0;
}










