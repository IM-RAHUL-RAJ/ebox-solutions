#include<stdio.h>
#include<stdlib.h>

void oddoreven(int *a){
    if(*a%2==0){
        printf("%d is an even number",*a);
        
    }
    else{
        printf("%d is an odd number",*a);
    }
}

int main(){
    int x;
    printf("Enter the number");
    scanf("%d",&x);
    oddoreven(&x);
    return 0;
}
