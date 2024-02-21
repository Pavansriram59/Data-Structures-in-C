#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node* prev;
    int data;
    struct node* next;
}*newnode,*temp,*node_beg,*node_end,*node_pos;
struct node *head=NULL;
// head=(struct node*)malloc(sizeof(struct node));
struct node *tail=NULL;
// tail=(struct node*)malloc(sizeof(struct node));
void create(){
    char x;
    do{
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data:");
        scanf("%d",&newnode->data);
        newnode->prev=NULL;
        newnode->next=NULL;
        if(head==NULL){
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
        }
        fflush(stdin);
        printf("Enter choice 'Y' or 'y' to continue:");
        scanf("%c",&x);
    }while(x=='y');
}
void display(){
    temp=head;
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}
struct node* insert_beg(struct node *head){
    int val;
    node_beg=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value:");
    scanf("%d",&val);
    node_beg->prev=NULL;
    node_beg->data=val;
    node_beg->next=head;
    head->prev=node_beg;
    head=node_beg;
    return head;
}
void insert_end(){
    int val;
    node_end=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value:");
    scanf("%d",&val);
    node_end->data=val;
    node_beg->next=NULL;
    tail->next=node_end;
    node_end->prev=tail;
    tail=node_end;
}
void insert_pos(){
    int pos,val,i;
    node_pos=(struct node*)malloc(sizeof(struct node));
    temp=head;
    printf("Enter the pos and value to insert:");
    scanf("%d %d",&pos,&val);
    for(i=0;i<pos-1;i++){
        temp=temp->next;
    }
    node_pos->data=val;
    node_pos->next=temp->next;
    temp->next->prev=node_pos;
    temp->next=node_pos;
    node_pos->prev=temp;
}
void del_beg(){
    temp=head;
    head=head->next;
    temp->next=NULL;
    head->prev=NULL;
}
void del_end(){
    temp=tail;
    tail=tail->prev;
    temp->prev=NULL;
    tail->next=NULL;
}
void del_pos(){
    int pos,i;
    printf("Enter the pos to delete:");
    scanf("%d",&pos);
    temp=head;
    for(i=0;i<pos;i++){
        temp=temp->next;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    temp->prev=NULL;
    temp->next=NULL;
    free(temp);
}
void rev_list(){
    temp=tail;
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp=temp->prev;
    }
    printf("%d",temp->data);
}
void main(){
    int choice;
    do{
        int data,val;
        printf("\nEnter your choice:\n1.Creating and Printing the list\n2.Inserting\n3.Deletion\n4.Insertion at start\n5.Insertion at end\n6.Deletion at start\n7.Deletion at end\n8.Reversing the list\n9.Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            create();
            display(head);
            break;
            case 2:
            insert_pos();
            display(head);
            break;
            case 3:
            del_pos();
            printf("The elements after deleting:\n");
            display(head);
            break;
            case 4:
            head=insert_beg(head);
            display(head);
            break;
            case 5:
            insert_end(tail);
            display(head);
            break;
            case 6:
            del_beg();
            display(head);
            break;
            case 7:
            del_end();
            display(head);
            break;
            case 8:
            rev_list();
            display(head);
            case 9:
            exit(0);
            break;
        }
    }while(choice<10);
}
