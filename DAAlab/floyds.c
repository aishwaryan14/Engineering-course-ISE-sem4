#include<stdio.h>
#include<stdlib.h>
# define l 5

int min(int a,int b){
    if(a<b)
     return a;
    else 
     return b;
}

void floyd(int r[l][l],int n){
    int i,j,k;
     for(k=0;k<n;k++)
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                r[i][j]=min(r[i][j],(r[i][k]+r[k][j]));
    }

void main(){
    int i,j,n;
    printf("Enter the no of vertices:\n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix:\n");
    int r[l][l];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&r[i][j]);
        }
    }
    floyd(r,n);
    printf("The all pairs shortest path is:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",r[i][j]);
        }
        printf("\n");
    }
}

