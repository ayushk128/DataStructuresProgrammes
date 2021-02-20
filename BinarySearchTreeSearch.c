#include <stdio.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *createNode(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}
void inOrder(struct node *root)
{
    if(root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int isBST(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if(!isBST(root->left))
        {
            return 0;
        }
        if(prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return (isBST(root->right));
    }
    else
    {
        return 1;
    }
    
}
int search(struct node *root, int key)
{
    if(root == NULL)
    {
        return 0;
    }
    if(root->data == key)
    {
        return 1;
    }
    else if(root->data > key)
        return search(root->left, key);
    else 
        return search(root->right, key);    
}
int searchIter(struct node *root, int key)
{
    while(root != NULL)
    {
        if(key == root->data)
        {
            return 1;
        }
        else if(key < root->data)
        {
            root = root->left;
        }
        else 
            root = root->right;
    }
    return 0;
}
int main()
{
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);

    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;
    inOrder(p);
    printf("\n");
    printf("%d", isBST(p));
    printf("\n");
    int searched = search(p, 4);
    printf("%d ", searched);
    int seardhedI = searchIter(p, 20);
    printf("%d ", seardhedI);
}