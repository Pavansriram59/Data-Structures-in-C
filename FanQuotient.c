#include<stdio.h>
#include<string.h>
/*Fans with higher fan quotient should be outputted first and 
in case of a tie, the lexicographically minimum name should come first.*/
struct fan_quo
{
    char name[100];//creating structure for names and fanquotient
    int quo;
};
void main(){
    int max,n;
    printf("Enter the no of fans and  max no of fans:");
    scanf("%d %d",&n,&max);
    struct fan_quo f[n];
    printf("Enter the names and quotient:\n");
    for(int i=0;i<n;i++){
        scanf("%s %d",&f[i].name,&f[i].quo);
    }
    struct fan_quo temp;
    for(int i=0;i<n;i++){//lopp for fan quotients and names
        for(int j=i+1;j<n;j++){
            if(f[i].quo<f[j].quo){//for fan quotients
                temp=f[i];
                f[i]=f[j];
                f[j]=temp;
            }
            if(f[i].quo==f[j].quo){//if fan quotiets are equal
                if(strcmp(f[i].name,f[j].name)>0){
                    temp=f[i];
                    f[i]=f[j];
                    f[j]=temp;
                }
            }
        }
    }
    printf("\n");
    for(int i=0;i<max;i++)//printing names max needed
    printf("%s\n",f[i].name);
}
