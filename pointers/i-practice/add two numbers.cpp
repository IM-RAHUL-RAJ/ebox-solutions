#include<stdio.h>
#include<stdlib.h>

void addition(int *a,int *b){
    printf("Sum of two elements = %d", *a+*b);
}

int main(){
    int x,y;
    printf("Enter the value of a");
    scanf("%d",&x);
    printf("Enter the value of b");
    scanf("%d",&y);
    addition(&x,&y);
    return 0;
    
}
