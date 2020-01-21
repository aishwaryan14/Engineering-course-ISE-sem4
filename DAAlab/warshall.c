#include<stdio.h>
#include<stdlib.h>
# define l 5
void warshall(int r[l][l],int n){
    int i,j,k;
     for(k=0;k<n;k++)
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                r[i][j]=(r[i][j]||(r[i][k]&&r[k][j]));
    }

void main(){
    int i,j,n;
    printf("Enter the vertices:\n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix:\n");
    int r[l][l];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&r[i][j]);
        }
    }
    warshall(r,n);
    printf("The transitive closure is:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",r[i][j]);
        }
        printf("\n");
    }
}

