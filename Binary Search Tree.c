#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;                  
    struct node *right_child;
    struct node *left_child;
}*new,*temp;
struct node* new_node(int x)
{
    new = malloc(sizeof(struct node));
    new->data = x;
    new->left_child = NULL;
    new->right_child = NULL;

    return new;
}
struct node* insert(struct node *root, int x)
{
    //searching for the place to insert
    if(root==NULL)
        return new_node(x);
    else if(x>root->data)
        root->right_child = insert(root->right_child, x);
    else
        root->left_child = insert(root->left_child,x);
    return root;
}
void inorder(struct node *root)
{
    if(root!=NULL) // checking if the root is not null
    {
        inorder(root->left_child);
        printf(" %d ", root->data);
        inorder(root->right_child);
    }
}
void preorder(struct node *root)
{
    if(root!=NULL) // checking if the root is not null
    {
        printf(" %d ", root->data);
   preorder(root->left_child);
        preorder(root->right_child);
    }
}
void postorder(struct node *root)
{
    if(root!=NULL) // checking if the root is not null
    {
        postorder(root->left_child);
        postorder(root->right_child);
   printf(" %d ", root->data);

    }
}
struct node* search(struct node *root, int x)
{
    if(root==NULL || root->data==x)
        return root;
    else if(x>root->data)          
        return search(root->right_child, x);
    else                          
        return search(root->left_child,x);
}
struct node* find_minimum(struct node *root)
{
    if(root == NULL)
        return NULL;
    else if(root->left_child != NULL) // node with minimum value will have no left child
        return find_minimum(root->left_child); // left most element will be minimum
    return root;
}
// function to delete a node
struct node* delete(struct node *root, int x)
{
    //searching for the item to be deleted
    if(root==NULL)
        return NULL;
    if (x>root->data)
        root->right_child = delete(root->right_child, x);
    else if(x<root->data)
        root->left_child = delete(root->left_child, x);
    else
    {
        //No Children
        if(root->left_child==NULL && root->right_child==NULL)
        {
            free(root);
            return NULL;
        }

        //One Child
        else if(root->left_child==NULL || root->right_child==NULL)
        {
            struct node *temp;
            if(root->left_child==NULL)
                temp = root->right_child;
            else
                temp = root->left_child;
            free(root);
            return temp;
        }

        //Two Children
        else
        {
            struct node *temp = find_minimum(root->right_child);
            root->data = temp->data;
            root->right_child = delete(root->right_child, temp->data);
        }
    }
    return root;
}
int main()
{
    struct node *root;
    int ch,val,c=1;
    root = new_node(20);
    printf("\n1.Insert\n2.Delete\n3.inorder\n4.preorder\n5.postorder\n6.search\n7.Exit\n");
    while(c==1){
        printf("\nEnter the choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter the element to insert:");
                scanf("%d",&val);
                insert(root,val);
                break;
            case 2:
                printf("Enter the element to delete:");
                scanf("%d",&val);
                root=delete(root,val);
                break;
            case 3:
                inorder(root); break;
            case 4:
                preorder(root); break;
            case 5:
                postorder(root); break;
            case 6:
                printf("Enter the element to search :");
                scanf("%d",&val);
                temp=search(root,val);
                (temp!=NULL)?printf("Element found"):printf("Not found");
                break;
            case 7:c=0;break;
        }
    }
    return 0;
}
