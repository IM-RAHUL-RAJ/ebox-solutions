#include<stdio.h>
#include<stdlib.h>

int **create(int m,int n){
    int i,**ptr;
    ptr=(int **)malloc(m*sizeof(int *));
    for(i=0;i<m;i++){
        *(ptr+i)=(int *)malloc(n*sizeof(int));
    }
    return ptr;
    
}
void enter(int **ptr,int m,int n){
    int i,j;
    printf("\nEnter the elements in the matrix");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",*(ptr+i)+j);
        }
    }
}
void display(int **ptr,int m,int n){
    int i,j,sum=0;
    
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            sum=sum+*(*(ptr+i)+j);
        }
    }
    printf("\nThe sum of the elements in the matrix is %d",sum);
}


int main(){
    
    int m,n,**a;
    printf("Enter the number of rows in the matrix");
    scanf("%d",&m);
    printf("\nEnter the number of columns in the matrix");
    scanf("%d",&n);
    a=create(m,n);
    enter(a,m,n);
    display(a,m,n);
    return 0;
    
}
