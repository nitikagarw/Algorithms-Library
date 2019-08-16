/******************************
Program to create a BINARY TREE
******************************/
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
    printf("the tree is now : \n");
    inorder(root);
    return 0;
}










