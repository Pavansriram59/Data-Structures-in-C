#include <stdio.h>
#include <stdlib.h>

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
    int key = val % SIZE;
    if (a[key] == -1)
    {
        a[key] = val;
        printf("%d inserted at a[%d]\n",val,key);
    }
    else{
        printf("Collision Occurs:\n");
        printf("Unable to insert %d\n",val);
    }
}
void search(int val){
    int key=val%SIZE;
    if(a[key]==val)
    printf("Element found\n");
    else printf("Element not found\n");
}
void delete(int val){
    int key=val%SIZE;
    if(a[key]==val)
    a[key]=-1;
    else printf("%d not present in hash table\n",val);
}
void display(){
    for(int i=0;i<SIZE;i++){
        printf("a[%d]=%d\n",i,a[i]);
    }
}
void main()
{
    int ch;
    array();
    do{
        int n,val;
        printf("\nEnter your choice:\n1.Inserting\n2.Searching\n3.Printing\n4.Deletion\n5.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter the size:");
                scanf("%d",&n);
                printf("Enter the elements:\n");
                while(n){
                    scanf("%d",&val);
                    insert(val);
                    n--;
            }
            break;
            case 2:
                printf("Enter the element to search:");
                scanf("%d",&val);
                search(val);
            break;
            case 3:
                printf("The hash table is:\n");
                display();
                break;
            case 4:
                printf("Enter the value to delete");
                scanf("%d",&val);
                delete(val);
                display();
            break;
            case 5:
                exit(0);
                break;
        }
    }while(ch<6);
}
