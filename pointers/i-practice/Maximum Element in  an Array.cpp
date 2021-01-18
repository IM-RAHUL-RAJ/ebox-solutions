#include<stdio.h>
#include<stdlib.h>

int main(){
    int i,n,max,*ptr;
    
    printf("Enter the number of elements in an array");
    scanf("%d",&n);
    ptr=(int *)malloc(n*sizeof(int));
    
    printf("\nEnter the array elements");
    for(i=0;i<n;i++){
        scanf("%d",ptr+i);
    }
    max=*ptr;
    for(i=1;i<n;i++){
        if(*(ptr+i)>max){
            max=*(ptr+i);
        }
    }
    printf("\n%d is the maximum element in the array",max);
    return 0;
}
