#include <stdio.h>
#include <stdlib.h>

#define SIZE 7
struct node
{
    int data;
    struct node *next;
} * newnode, *temp;

struct node *a[SIZE];
void array()
{
    for (int i = 0; i < SIZE; i++)
    {
        a[i] = NULL;
    }
}
void insert(int val)
{
    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = val;
    newnode->next = NULL;
    int i = val % SIZE;
    if (a[i] == NULL)
    {
        a[i] = newnode;
    }
    else
    {
        temp = a[i];
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
void display()
{
    for (int i = 0; i < SIZE; i++)
    {
        temp = a[i];
        printf(" a[%d] --> ", i);
        while (temp)
        {
            printf(" %d --> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
void search(int val){
    int i=val%SIZE;
    temp=a[i];
    int flag=0;
    while(temp){
        if(temp->data==val){
            flag=1;
            break;
        }
        temp=temp->next;
    }
    if(flag==1)
    printf("Element found\n");
    else
    printf("Element not found\n");
}
void main()
{
    array();
    int n, val;
    printf("Enter no of elements:");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    while (n)
    {
        scanf("%d", &val);
        insert(val);
        n--;
    }
    display();
    printf("Enter the element to search:");
    scanf("%d",&val);
    search(val);
}
