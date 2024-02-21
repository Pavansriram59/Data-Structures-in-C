#include<stdio.h>
#include<stdlib.h>
struct queue{
    int data;
    struct queue *next;
}*newnode,*temp;
struct queue *front=NULL;
struct queue *rear=NULL;
void enqueue_end(){
    int val;
    printf("Enter the val:");
    scanf("%d",&val);
    newnode=(struct queue*)malloc(sizeof(struct queue));
    newnode->data=val;
    newnode->next=NULL;
    if(front==NULL){
            front=newnode;
            rear=newnode;
    }
    else{
            rear->next=newnode;
            rear=newnode;
    }
}
void enqueue_beg(){
    int val;
    printf("Enter the val:");
    scanf("%d",&val);
    newnode=(struct queue*)malloc(sizeof(struct queue));
    newnode->data=val;
     newnode->data=val;
    newnode->next=NULL;
    newnode->next=front;
    front=newnode;
}
void dequeue_beg(){
    temp=front;
    int ele=front->data;
    front=front->next;
    free(temp);
    printf("\nPopped Element is %d\n",ele);
}
void dequeue_end(){
    temp=front;
    while(temp->next){
            newnode=temp;
            temp=temp->next;
    }
    int ele=temp->data;
    newnode->next=NULL;
    rear=newnode;
    printf("\nPopped Element is %d\n",ele);
}
void display(){
    temp=front;
    while(temp){
            printf("%d--> ",temp->data);
            temp=temp->next;
    }
    printf("NULL\n");
}
void main(){
    int x;
    do{
            printf("\nEnter the choice:\n1.Enqueue at end\n2.Dequeue at start\n3.Enqueue at start\n4.Dequeue at end\n5.Display\n6.Exit\n");
            scanf("%d",&x);
            switch(x){
                    case 1:
                        enqueue_end();
                        break;
                    case 2:
                        dequeue_beg();
                        break;
                    case 3:
                        enqueue_beg();
                        break;
                    case 4:
                        dequeue_end();
                        break;
                    case 5:
                        display();
                        break;
                    case 6:
                        exit(0);
                        break;
        }
    }while(x<6);
}
