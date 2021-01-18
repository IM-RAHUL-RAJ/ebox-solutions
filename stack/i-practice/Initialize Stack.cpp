#include<stdio.h>
#include<stdlib.h>

struct stack{
  int a[5];
  int top;
};

void initstack(struct stack *p){
    
    p->top=-1;
    // printf("The top of the stack is %d",p->top);
}

int main(){
    struct stack s;
    initstack(&s);
    
    printf("The top of the stack is %d",s.top);
    
    
    
    return 0;
    
    
}
