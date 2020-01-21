#include<stdio.h>
int count =0;

int bfs(int a[20][20],int n,int visited[20],int source)
{
    count++;
    int v,u;
    int f=0,r=-1;
    visited[source]=count;
    int queue[20];
    queue[++r]=source;
    while(f<=r){
    u=queue[f++];    
    for(v=1;v<=n;v++)
    {
        if(a[u][v]==1&&visited[v]==0)
        {
            queue[++r]=v;
            count++;
            visited[v]=count;
        }
     }
    }
}

void main()
{
    int n,a[20][20],i,j,visited[20],source,visitedorder[20];
    printf("Enter the no of vertices\n");
    scanf("%d",&n);
    printf("Enter the adjacency matrix\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    for(i=1;i<=n;i++)
        visited[i]=0;
    printf("Enter source node\n");
    scanf("%d",&source);
    bfs(a,n,visited,source);
    for(i=1;i<=n;i++)
        if(visited[i]==0)
            bfs(a,n,visited,i);
    for(i=1;i<=n;i++)
    {
        visitedorder[visited[i]]=i;
    }
    printf("BFS traversal= \n");
    for(i=1;i<=n;i++)
    {
        printf("%c \t",visitedorder[i]+64);
    }
}

