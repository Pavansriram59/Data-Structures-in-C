#include <stdio.h>
#include <stdlib.h>
struct node
{
    int coeff, expo;
    struct node *link;
} * newnode, *temp, *temp1, *temp2,*temp3, *head1 = NULL, *head2 = NULL,*head3=NULL;
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
        printf("Enter the choice 'y' to continue or 'n' to exit:");
        fflush(stdin);
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
struct node *poly_mul(struct node *head){
    temp1=head1;
    while(temp1){
        temp2=head2;
        while(temp2){
            newnode=(struct node*)malloc(sizeof(struct node));
            newnode->coeff=temp1->coeff*temp2->coeff;
            newnode->expo=temp1->expo+temp2->expo;
            newnode->link=NULL;
            if(head3==NULL){
                head3=newnode;
                tail=newnode;
            }
            else{
                tail->link=newnode;
                tail=newnode;
            }
        temp2=temp2->link;
        }
    temp1=temp1->link;
    }
    temp3=head3;
    temp1=head3->link;
    while(temp1){
        if(temp3->expo==temp1->expo){
            temp3->coeff=temp3->coeff+temp1->coeff;
            temp3->link=temp1->link;
            temp3=temp3->link;
            temp1=temp3->link;
        }
        else{
            temp3=temp1;
            temp1=temp3->link;
        }
    }
    return head3;
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
    // printf("\nThe polynomials sum is:\n");
    // poly_add(head1,head2);
    printf("\nThe Multiplication of two polynomials is:\n");
    head3=poly_mul(head3);
    display(head3);
} 
