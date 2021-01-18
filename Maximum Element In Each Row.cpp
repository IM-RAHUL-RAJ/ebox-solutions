#include<stdio.h>
#include<stdlib.h>

void maxim(int **p,int m,int n){
    int max=0,i,j;
    for(i=0;i<m;i++){
        
        for(j=0;j<n;j++){
            if(*(*(p+i)+j)>max){
                max=*(*(p+i)+j);
            }
        }
        printf("\n%d",max);
        max=0;
    }
}

int main(){
    int m,n,**matrix,i,j;
    
    printf("Enter the number of rows in the matrix");
    scanf("%d",&m);
    printf("\nEnter the number of columns in the matrix");
    scanf("%d",&n);
    printf("\nEnter the elements in the matrix");
    
    matrix=(int **)malloc(m*sizeof(int *));
    
    for(i=0;i<m;i++){
        *(matrix+i)=(int *)malloc(n*sizeof(int));
    }
    
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",*(matrix+i)+j);
        }
    }
    
    maxim(matrix,m,n);
    
    return 0;
}
