#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
}*newnode,*temp;
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
        newnode->link=NULL;
        if(head==NULL){
            head=newnode;
            tail=newnode;
        }
        else{
            tail->link=newnode;
            tail=newnode;
        }
        fflush(stdin);
        printf("Enter choice 'Y' or 'y' to continue:");
        scanf("%c",&x);
    }while(x=='y');
}
void display(struct node *head){
    temp=head;
    while(temp!=NULL){
        printf("%d %u\n",temp->data,temp->link);
        temp=temp->link;
    }
}
void count_node(struct node* head){
    int c=0;
    if(head==NULL)
    printf("The list is empty");
    while(head!=NULL){
        c++;
        head=head->link;
    }
    printf("No of Nodes are:%d",c);
}
void insert_end(struct node *tail,int data){
    struct node *node_end;
    node_end=(struct node*)malloc(sizeof(struct node));
    node_end->data=data;
    node_end->link=NULL;
    tail->link=node_end;
    tail=node_end;
    // while(head->link!=NULL){
    //     head=head->link;
    // }
    // head->link=node_end;
}
struct node *insert_beg(struct node *head,int val){
    struct node *node_beg;
    node_beg=(struct node*)malloc(sizeof(struct node));
    node_beg->data=val;
    node_beg->link=NULL;
    //inserting a node at beginning
    node_beg->link=head;
    head=node_beg;
    return head;
}
void del_beg(){
    temp=head;
    head=head->link;
    temp->link=NULL;
}
void del_end(){
    temp=head;
    while(temp->link!=NULL){
        temp=temp->link;
    }
    temp->link=NULL;
    tail=temp;
}
void insert_pos(){
    int pos,val,i;
    temp=head;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the position and value:");
    scanf("%d %d",&pos,&val);
    for(i=0;i<pos-1;i++){
        temp=temp->link;
    }
    newnode->data=val;
    newnode->link=temp->link;
    temp->link=newnode;
}
void delete_pos(){
    int pos,i,c=0;
    struct node *prev=head;
    temp=head;
    printf("Enter the pos to delete:");
    scanf("%d",&pos);
    while(temp->link!=NULL){
        c++;
        if(c==pos){
            prev->link=temp->link;
        }
        prev=temp;
        temp=temp->link;
    }
}
void rev_list(){
    struct node *prev=NULL;
    struct node *next=NULL;
    while(head!=NULL){
        next=head->link;
        head->link=prev;
        prev=head;
        head=next;
    }
    head=prev;
}
void main(){
    int choice;
    do{
        int data,val;
        printf("\nEnter your choice:\n1.Creating and Printing the list\n2.Inserting\n3.Deletion\n4.Counting\n5.Insertion at end\n6.Insertion at start\n7.Deletion at start\n8.Deletion at end\n9.Reversing the list\n10.Exit\n");
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
            delete_pos();
            printf("The elements after deleting:\n");
            display(head);
            break;
            case 4:
            count_node(head);
            break;
            case 5:
            printf("Enter the data to insert at end:");
            scanf("%d",&data);
            // insert_end=(head,data);
            insert_end(tail,data);
            display(head);
            break;
            case 6:
            printf("Enter the data to insert at beginning:");
            scanf("%d",&val);
            head=insert_beg(head,val);
            display(head);
            break;
            case 7:
            del_beg();
            display(head);
            break;
            case 8:
            del_end();
            display(head);
            break;
            case 9:
            rev_list();
            display(head);
            break;
            case 10:
            exit(0);
            break;
        }
    }while(choice<11);
}
