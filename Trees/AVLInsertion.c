/****************************************
Program to perform INSERTION in AVL Trees
****************************************/
#include<stdio.h>
#include<stdlib.h>
struct node
          {
              struct node* left;
              int info;
              struct node* right;
              int height;
          };

int maximum(int a, int b);
int height(struct node* temp);
int GetBalance(struct node *temp);
struct node* CreateNode(int value);
struct node* LeftRotate(struct node *x);
struct node* RightRotate(struct node *x);
struct node* AVLinsert(struct node *temproot, int value);
void inorder(struct node *root);

int main()
{
    struct node *root = NULL;
    //Insertion
    root = AVLinsert(root, 10);
    root = AVLinsert(root, 20);
    root = AVLinsert(root, 30);
    printf("\nThe Tree is now :\n\t\t");
    inorder(root);

    root = AVLinsert(root, 40);
    root = AVLinsert(root, 50);
    printf("\nThe Tree is now :\n\t\t");
    inorder(root);

    root = AVLinsert(root, 60);

    //Display
    printf("\nThe Tree is now :\n\t\t");
    inorder(root);

    printf("\nHeight of the root : %d\n", root->height);
    return 0;
}

int maximum(int a, int b)
{
    return ((a > b)? a : b) ;
}

int height(struct node* temp)
{
    if(temp == NULL)
        return -1;
    else
        return temp->height;
}

struct node* CreateNode(int value)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->info = value;
    newNode->right = NULL;
    newNode->left = NULL;
    newNode->height = 0;
    return newNode;
}

int GetBalance(struct node *temp)
{
    if(temp == NULL)
        return 0;
    else
        return (height(temp->left)- height(temp->right));
}

struct node* LeftRotate(struct node *x)
{
    struct node * y;
    y = x->right;
    x->right = y->left;
    y->left = x;

    y->height = maximum(height(y->left), height(y->right)) + 1;
    x->height = maximum(height(x->left), height(x->right)) + 1;
    return(y);
}

struct node* RightRotate(struct node *x)
{
    struct node * y;
    y = x->left;
    x->left = y->right;
    y->right = x;

    y->height = maximum(height(y->left), height(y->right)) + 1;
    x->height = maximum(height(x->left), height(x->right)) + 1;
    return(y);

}

struct node* AVLinsert(struct node *temproot, int value)
{
    struct node *newNode;
    newNode = CreateNode(value);

    if(temproot == NULL)
        return newNode;
    else if(value < temproot->info)
        temproot->left = AVLinsert(temproot->left, value);
    else
        temproot->right = AVLinsert(temproot->right, value);

    temproot->height = maximum(height(temproot->left), height(temproot->right)) + 1;

    int Balance = GetBalance(temproot);

    if(Balance > 1)
    {
        if(value < temproot->left->info)
            return RightRotate(temproot);
        else if(value > temproot->left->info)
        {
            temproot->left = LeftRotate(temproot->left);
            return RightRotate(temproot);
        }
    }
    else if(Balance < 1)
    {
        if(value > temproot->right->info)
            return LeftRotate(temproot);
        else if(value < temproot->right->info)
        {
            temproot->right = RightRotate(temproot->right);
            return LeftRotate(temproot);
        }
    }

    return temproot;
}

void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%3d", root->info);
        inorder(root->right);
    }
    return;
}







