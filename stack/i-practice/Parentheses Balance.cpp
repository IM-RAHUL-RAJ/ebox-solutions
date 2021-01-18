#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

struct stack {
    char *s;    
    int top;  
};
void initstack(struct stack *p){
    p->top=-1;
    p->s=(char *)malloc(128*sizeof(char));
}
void push(struct stack *p,char item){
    p->top++;
    p->s[p->top]=item;
}
char pop(struct stack *p){
    char x;
    x=p->s[p->top];
    p->top--;
    return x;
    
}
void balancedornot(struct stack p,char *par){
    int i;
    initstack(&p);
    for(i=0;i<strlen(par);i++){
        if(par[i]==')'){
            if(pop(&p)!='('){
                printf("No\n");
                return;
            }
        }
    
    else if(par[i]==']'){
        if(pop(&p)!='['){
            printf("No\n");
            return;
        }
    }
    else{
        push(&p,par[i]);
    }
    }
    // printf("%s\n",(p.top==-1)?"Yes" : "No");
    if(p.top==-1){
        printf("Yes");
    }
    
    

}
int main(){
    struct stack st;
    char s[128];
    // st.s=(struct stack *)malloc(sizeof(struct stack));
    initstack(&st);
    int n;
    
    scanf("%d",&n);
    
    while(n){
        scanf("%s",s);
        balancedornot(st,s);
        n--;
    }
    
    return 0;
    
    
}
