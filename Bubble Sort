#include<stdio.h>
int main(){
    int i,j,k,n,temp,c=0;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    for(j=0;j<n;j++){
        for(k=j+1;k<n;k++){
            if(a[j]>a[k]){
                temp=a[j];
                a[j]=a[k];
                a[k]=temp;
                c++;
            }
        }
    }
    printf("Array is sorted in %d swaps.\n",c);
    printf("First Element: %d\n",a[0]);
    printf("Last Element: %d\n",a[n-1]);
}
