//. Linear probing
#include<stdio.h>
#include<stdlib.h>
#define SIZE 7
int a[SIZE];

void array()
{
    for (int i = 0; i < SIZE; i++)
    {
        a[i] = -1;
    }
}

void insert(int val)
{
    int key = val % SIZE,i,index=0;
    for(i=0;i<SIZE;i++){
        index=(key+i)%SIZE;
        if(a[index]==-1){
            a[index]=val;
            break;
        }
    }
    if(i==SIZE)
    printf("\nElement can't be inserted.\n");
}
void display(){
    for(int i=0;i<SIZE;i++){
        printf("a[%d]=%d\n",i,a[i]);
    }
}
void search(int val){
    int key=val%SIZE,i,index=0;
    if(a[key]==val)
    printf("%d element found",val);
    else{
        for(i=0;i<SIZE;i++){
            index=(key+i)%SIZE;
            if(a[index]==val){
                printf("%d element found",val);
                break;
            }
        }
        printf("%d ele not found",val);
    }
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
    search(45);
}
// Quadratic probing

#include<stdio.h>
#include<stdlib.h>
#define SIZE 7
int a[SIZE];

void array()
{
    for (int i = 0; i < SIZE; i++)
    {
        a[i] = -1;
    }
}

void insert(int val)
{
    int key = val % SIZE,i,index=0;
    for(i=0;i<SIZE;i++){
        index=(key+i*i)%SIZE;
        if(a[index]==-1){
            a[index]=val;
            break;
        }
    }
    if(i==SIZE)
    printf("\nElement can't be inserted.\n");
}
void display(){
    for(int i=0;i<SIZE;i++){
        printf("a[%d]=%d\n",i,a[i]);
    }
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
}
