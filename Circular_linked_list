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
            tail->link=head;
        }
        fflush(stdin);
        printf("Enter choice 'Y' or 'y' to continue:");
        scanf("%c",&x);
    }while(x=='y');
}
void display(struct node *head){
    temp=head;
    while(temp->link!=head){
        printf("%d\n",temp->data);
        temp=temp->link;
    }
    printf("%d",temp->data);
}
struct node *insert_beg(struct node *head,int val){
    struct node *node_beg;
    node_beg=(struct node*)malloc(sizeof(struct node));
    node_beg->data=val;
    //inserting a node at beginning
    node_beg->link=head;
    tail->link=node_beg;
    head=node_beg;
    return head;
}
void insert_end(struct node *tail,int data){
    struct node *node_end;
    node_end=(struct node*)malloc(sizeof(struct node));
    node_end->data=data;
    node_end->link=NULL;
    tail->link=node_end;
    node_end->link=head;
    tail=node_end;
    // while(head->link!=NULL){
    //     head=head->link;
    // }
    // head->link=node_end;
}
void insert_pos(){
    int pos,val,i;
    temp=head;
    struct node *node_pos;
    node_pos=(struct node*)malloc(sizeof(struct node));
    printf("Enter the position and value:");
    scanf("%d %d",&pos,&val);
    for(i=0;i<pos-1;i++){
        temp=temp->link;
    }
    node_pos->data=val;
    node_pos->link=temp->link;
    temp->link=node_pos;
}
void del_beg(){
    temp=head;
    head=head->link;
    tail->link=head;
    temp->link=NULL;
}
void del_end(){
    temp=head;
    while(temp->link!=tail){
        temp=temp->link;
    }
    tail->link=NULL;
    temp->link=head;
    tail=temp;
}
void delete_pos(){
    int pos,i;
    printf("Enter the position to delete:");
    scanf("%d",pos);
    temp=head;
    for(i=0;i<pos-1;i++){
        temp=temp->link;
    }
    temp->link=temp->link->link;
}
void main(){
    int choice;
    do{
        int data,val;
        printf("\nEnter your choice:\n1.Creating and Printing the list\n2.Inserting\n3.Deletion\n4.Insertion at end\n5.Insertion at start\n6.Deletion at start\n7.Deletion at end\n8.Exit\n");
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
            printf("Enter the data to insert at end:");
            scanf("%d",&data);
            // insert_end=(head,data);
            insert_end(tail,data);
            display(head);
            break;
            case 5:
            printf("Enter the data to insert at beginning:");
            scanf("%d",&val);
            head=insert_beg(head,val);
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
            exit(0);
            break;
        }
    }while(choice<9);
}
