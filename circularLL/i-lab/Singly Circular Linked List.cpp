#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct term
{
    int coeff ;
    int x,y,z;
    struct term * next;
} ;
void display(struct term* poly);
void polyappend ( struct term **poly, int coeff, int x,int y,int z ){
   struct term * r= (struct term *) malloc(sizeof (struct term));
  struct term *temp=*poly;
  r->coeff=coeff;
  r->x=x;
  r->y=y;
  r->z=z;
  //r->next= NULL;
  if(*poly== NULL){
   *poly=r;
   r->next=*poly;
   return;
  }
  
    while(temp->next!=(*poly)) {
      temp=temp->next;
    }
    temp->next=r;
    r->next=(*poly);

}

struct term * polyadd(struct term *poly1, struct term *poly2){
    int i=0,j=0,a[100],b[100],c[100],d[100],k,l,m,n,flag=0,o=0;
   struct term* r=poly1;
   struct term* t=poly2;
   do{
       a[j]=r->x;
       b[j]=r->y;
       c[j]=r->z;
       d[j]=r->coeff;
       r=r->next;
       j++;
   }while(r!=poly1);
   
   do{k=t->x;
     l=t->y;
     m=t->z;
     n=t->coeff;
     while(o<j){
         if(a[o]==k && b[o]==l && c[o]==m){
             d[o]=d[o]+n;
             flag=1;
         }
         o++;
     }
      if(flag==1)
      continue;
       a[j]=t->x;  
       b[j]=t->y;  
       c[j]=t->z;
       d[j]=t->coeff;
       t=t->next;
       j++;
   }while(t!=poly2);
   
    struct term *nn=NULL;
   
    while(i < j){
       polyappend(&nn,d[i],a[i],b[i],c[i]);
       
        i++;
    }
   
    return nn;
}
void evaluate(struct term** p){
  
    struct term* r=*p;
    int x,y,z;
    float sum=0.0;
    printf("Enter x, y, z, terms to evaluate \n\n");
    scanf("%d %d %d",&x,&y,&z);
    do{
        sum=sum+(r->coeff*pow(x,r->x)*pow(y,r->y)*pow(z,r->z));
        r=r->next;
    }while(r!=(*p));
    printf("Polynomial result is %0.6f\n\n\n",sum);
}
void display(struct term *poly){
    struct term *r=poly;
 do{
    printf("%d %c%c%d %c%c%d %c%c%d ",r->coeff,'x','^',r->x,'y','^',r->y,'z','^',r->z);
    if(r->next!=poly)
    printf("%c ",'+');
    r=r->next;
    }while(r!=poly);
    //printf("%d %c%c%d %c%c%d %c%c%d",r->coeff,'x','^',r->x,'y',''^',r->y,'z','^',r->z);
    printf("\n");
}
int main(){
  struct term* p=NULL;
  struct term* q=NULL;
  struct term* nn=NULL;
  int n,coef,x,y,z,c,coef1,coef2,x1,y1,z1,x2,y2,z2;
  while(1){
      printf("1 Evaluate polynomial\n2 Add two polynomials\n3 Exit\n");
      printf("Enter your choice \n\n");
      scanf("%d",&c);
      if(c==1){
          printf("Enter polynomial to evaluate \n");
          while(1){
          printf("Enter coeff\n");
          scanf("%d",&coef);
          printf("Enter x, y, z powers(0-indiacate NO term)\n");
          scanf("%d %d %d",&x,&y,&z);
          printf("If you wish to continue press 1 otherwise 0\n");
          scanf("%d",&n);
          polyappend(&p,coef,x,y,z);
          if(n==0)
          break;
          }
          printf("\n");
          display(p);
          printf("\n");
          evaluate(&p);
      }
      else if(c==2){
          printf("Enter the first polynomial ");
          while(1){
          printf("Enter coeff\n");
          scanf("%d",&coef1);
          printf("Enter x, y, z powers(0-indiacate NO term)\n");
          scanf("%d %d %d",&x1,&y1,&z1);
          polyappend(&p,coef1,x1,y1,z1);
          printf("If you wish to continue press 1 otherwise 0\n");
          scanf("%d",&n);
          if(n==0)
          break;
          }
          printf("\n");
          printf("Enter the second polynomial ");
          while(1){
              
              printf("Enter coeff\n");
              scanf("%d",&coef2);
              printf("Enter x, y, z powers(0-indiacate NO term)\n");
              scanf("%d %d %d",&x2,&y2,&z2);
              polyappend(&q,coef2,x2,y2,z2);
              printf("If you wish to continue press 1 otherwise 0\n");
              scanf("%d",&n);
              if(n==0)
              break;
          }
          printf("\n");
          printf("First polynomial is \n");
          display(p);
          printf("\nSecond polynomial is \n");
          display(q);
          printf("\nThe sum of 2 polynomials is \n");
         nn=polyadd(p,q);
         display(nn);
         printf("\n\n");
      }
      else if(c==3){
         
          break;
      }
  }
  return 0;
}
