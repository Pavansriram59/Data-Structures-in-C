#include <stdio.h>
#include <stdlib.h>
struct node
{
    int coeff, expo;
    struct node *link;
} * newnode, *temp, *temp1, *temp2, *head1 = NULL, *head2 = NULL;
struct node *head = NULL;
struct node *tail = NULL;
struct node *create(struct node *head)
{
    int co, ex;
    char x;
    do
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the coeff and expo:");
        scanf("%d %d", &co, &ex);
        newnode->coeff = co;
        newnode->expo = ex;
        newnode->link = NULL;
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->link = newnode;
            tail = newnode;
        }
        fflush(stdin);
        printf("Enter the choice 'y' to continue or 'n' to exit:");
        scanf("%c", &x);
    } while (x == 'y');
    return head;
}
void display(struct node *head)
{
    temp = head;
    while (temp->link != NULL)
    {
        printf("%dx^%d", temp->coeff, temp->expo);
        temp = temp->link;
        if (temp->coeff >= 0) {
            if (temp->link != NULL)
                printf("+");
        }
    }
    printf("+%dx^%d",temp->coeff,temp->expo);
}
void poly_add(struct node *head1, struct node *head2)
{
    temp1 = head1;
    temp2 = head2;
    while (temp1 && temp2)
    {
        if (temp1->expo == temp2->expo)
        {
            printf("%dx^%d+", temp1->coeff + temp2->coeff, temp1->expo);
            temp1 = temp1->link;
            temp2 = temp2->link;
        }
        else if (temp1->expo > temp2->expo)
        {
            printf("%dx^%d+", temp1->coeff, temp1->expo);
            temp1 = temp1->link;
        }
        else
        {
            printf("%dx^%d+", temp2->coeff, temp2->expo);
            temp2 = temp2->link;
        }
    }
    if(temp1==NULL){
        while(temp2!=NULL){
            printf("%dx^%d+",temp2->coeff,temp2->expo);
            temp2=temp2->link;
        }
    }
    else{
        while(temp1!=NULL){
            printf("%dx^%d+",temp1->coeff,temp1->expo);
            temp1=temp1->link;
        }
    }
}
void main(){
    printf("Enter the 1st polynomial:\n");
    head1=create(head1);
    printf("\nEnter the 2nd polynomial:\n");
    head2=create(head2);
    printf("polynomial 1 is:\n");
    display(head1);
    printf("\npolynomial 2 is:\n");
    display(head2);
    printf("\nThe polynomials sum is:\n");
    poly_add(head1,head2);
}
