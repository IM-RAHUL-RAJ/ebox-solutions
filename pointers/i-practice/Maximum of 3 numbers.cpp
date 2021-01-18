#include<stdio.h>
#include<stdlib.h>

int maximum(int *a,int *b,int *c){
    int max;
    max=*a;
    if(*b>*a){
        max=*b;
        
        if(*c>*b){
            max=*c;
            return max;
        }
        return max;
    }
    if(*c>*a){
        max=*c;
        return max;
    }
    return max;
    
}

int main(){
    int result=0;
    int x,y,z;
    printf("Enter the value of a");
    scanf("%d",&x);
    printf("Enter the value of b");
    scanf("%d",&y);
    printf("Enter the value of c");
    scanf("%d",&z);
    result=maximum(&x,&y,&z);
    printf("Maximum element is %d",result);
    return 0;
    
}
