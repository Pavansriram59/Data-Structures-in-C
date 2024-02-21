#include<stdio.h>
#include<stdlib.h>
int Top=-1;
void push(int a[],int n){
    int x;
    if(Top==n-1){
        printf("\nOverflow");
    }
    else{
        printf("Enter the element to insert:\n");
        scanf("%d",&x);
        Top++;
        a[Top]=x;
    }
}
void pop(int a[]){
    if(Top==-1){
        printf("\nUnderflow");
    }
    else{
        printf("\nPopped Element is: %d",a[Top]);
        Top--;
    }
}
void show(int a[]){
    if(Top==-1)printf("\nUnderflow");
    else{
        printf("Elements present in stack:\n");
        for(int i=Top;i>=0;i--)
        printf("%d ",a[i]);
    }
}
void max_ele(int a[],int n){
    int Top=n-1;
    int max=a[Top];
    for(int i=Top;i>=0;i--){
        if(a[i]>max)
        max=a[i];
    }
    printf("Maximum element in stack is: %d",max);
}
void main(){
    int n,choice;
    printf("Enter the size:");
    scanf("%d",&n);
    int a[n];
    while(1){
        printf("\nEnter your choice\n1.Inserting\n2.Deleting\n3.printing the stack\n4.Maximum element\n5.Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:push(a,n);
            break;
            case 2:pop(a);
            break;
            case 3:show(a);
            break;
            case 4:max_ele(a,n);
            break;
            case 5:
            exit(0);
            break;
        }
    }
}
