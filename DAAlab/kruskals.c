#include<stdio.h>
#define INFINITY 100

void kruskals(int n,int arr[10][10],int sourcenode){
    int cost[10][10],parent[10]={0};
    int min=INFINITY,mincost=0;
    int i,j,ne=1,u,v,a,b;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(arr[i][j]!=0)
            cost[i][j]=arr[i][j];
            else
            cost[i][j]=INFINITY;
        }
    }

    while(ne<n)
   {
  for(i=1,min=INFINITY;i<=n;i++)
   for(j=1;j<=n;j++)
    if(cost[i][j]<min)
       {
        min=cost[i][j];
        a=u=i;
        b=v=j;
        }
    while(parent[u])
     u=parent[u];
    while(parent[v])
     v=parent[v];
     if(u!=v)
     {
        printf("Edge %d:(%d->%d) cost:%d\n",ne++,a,b,min);
        mincost+=min;
        parent[v]=u;
     }
       cost[a][b]=cost[b][a]=INFINITY;
    }
    printf("The minimum cost:%d\n",mincost);
}

void main(){
    int i,j,n,sourcenode;
    int a[10][10];
    printf("Enter the no of vertices:\n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix:\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter the source node:\n");
    scanf("%d",&sourcenode);
    kruskals(n,a,sourcenode);
}

