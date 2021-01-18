#include<stdio.h>
#include<stdlib.h>
struct ticket{
    int number;
    struct ticket* link;
};
void append(struct ticket** p,int n);
void addafter(struct ticket* p,int pos,int n);
void display(struct ticket* p);
int count(struct ticket* p);
int main(){
    struct ticket* p=NULL;
    int n,pos,ele;
    //char s[10];
    while(1){
        printf("1.Enter ticket number occupying wrong seat\n2.Arrange the seating position\n3.Display current seating position\n4.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&n);
        if(n==1){
            printf("Enter the ticket number\n");
            scanf("%d",&ele);
        append(&p,ele);
}
        else if(n==3){
    display(p);
        }
   else if(n==2){
        printf("Enter the position of the ticket\n");
        scanf("%d",&pos);
        printf("Enter the ticket number\n");
        scanf("%d",&ele);
        addafter(p,pos,ele);
        
    }
    else if(n==4){
        printf("Exit\n");
        break;
    }
    }
    return 0;
}
void append(struct ticket** p,int n){
    
    struct ticket* temp=(struct ticket*)malloc(sizeof(struct ticket));
   struct ticket* r=*p;
   temp->number=n;
   if(*p==NULL){
       
       *p=temp;
       temp->link=*p;
       return;
   }
   while(*p!=r->link){
       r=r->link;
   }
   r->link=temp;
   temp->link=*p;
}
int count(struct ticket* p){
    struct ticket* q=p;
    int c=1;
    if(p==NULL){
        return 0;
    }
    while(q->link!=p){
        q=q->link;
        c++;
    }
    return c;
}
void addafter(struct ticket*p,int pos,int n){
    struct ticket* temp=(struct ticket*)malloc(sizeof(struct ticket));
    struct ticket* r=p;
    temp->number=n;
    //temp->link=NULL;
    int i,c;
    c=count(p);
    //printf("%d\n",c);
    if(pos>c){
        
        printf("No body has occupied ticket number %d at position %d.\n",n,pos);
        return;
    }
    else{
        for(i=1; i<pos; i++){
            r=r->link;
        }
        temp->link=r->link;
        r->link=temp;
        
    }
    printf("Wrong seat has been moved.\n");
}
void display(struct ticket* p){
    struct ticket* r=p;
    if(p==NULL){
        printf("List is empty\n");
    }
    else{
        printf("Seating position are:");
        do{
            printf("%d ",r->number);
            r=r->link;
        }while(r!=p);
    }
    printf("\n");
}
