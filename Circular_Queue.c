#include <stdio.h>
#include <stdlib.h>
#define MAX 6

int CQ[MAX];
int front = 0;
int rear = 0;
int count = 0;

void enqueue()
{
    int data;
    if (count == MAX){
        printf("\nCircular Queue is Full");
    }
    else{
        printf("Enter data: ");
        scanf("%d", &data);
        CQ[rear] = data;
        rear = (rear + 1) % MAX;
        count++;
    }
}
void dequeue()
{
    if (count == 0){
        printf("\n\nCircular Queue is Empty..");
    }
    else{
        printf("\n Deleted element from Circular Queue is %d ", CQ[front]);
        front = (front + 1) % MAX;
        count--;
    }
}
void display()
{
    int i, j;
    if (count == 0)
    {
        printf("\nCircular Queue is Empty ");
    }
    else{
        printf("\nElements in Circular Queue are: ");
        j = count;
        for (i = front; j != 0; j--){
            printf("%d ", CQ[i]);
            i = (i + 1) % MAX;
        }
    }
}
void main(){
    int choice;
    printf("\n1.Insert an element\n2.Delete an element\n3.Displaying\n4.Exit\n");
    while(1){
        printf("\nEnter the choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:enqueue();break;
            case 2:dequeue();break;
            case 3:display();break;
            case 4:exit(0);break;
        }
    }
}
