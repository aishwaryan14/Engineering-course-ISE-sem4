#include<stdio.h>
#include<stdlib.h>
int max(int a,int b){
    if(a>b)
     return a;
    else
     return b;
}
void knapsack(int m,int n,int w[],int p[]){
int v[20][20],x[10],i,j,sum=0;
int k;
for(i=0;i<n;i++){
    x[i]=-1;
}
for(i=0;i<=n;i++)
v[i][0]=0;
for(j=0;j<=m;j++)
v[0][j]=0;
 for(i=1;i<=n;i++)
  {
  for(j=1;j<=m;j++)
   {
     if(j>=w[i])
       v[i][j]=max(v[i-1][j],v[i-1][j-w[i]]+p[i]);
     else
       v[i][j]=v[i-1][j];    
    }
   }
   i=n;
   j=m;
  while(i>0 && j>0){
      if(v[i][j]!=v[i-1][j])
       {
         sum=sum+p[i];
         x[k]=p[i];
         j=j-w[i];
       }   
      i--;
     k++;
  }
  
  printf("Max profit is:%d\n",sum);
  printf("The profits are:\n");
  for(k=0;k<n;k++){
      if(x[k]!=-1){
      printf("%d ",x[k]);
  }}
}

void main()
{
int w[10],p[10],m,n,j,i;
printf("enter the number of items:\n");
scanf("%d",&n);
printf("enter the weights of the items:\n");
for(i=1;i<=n;i++)
scanf("%d",&w[i]);
printf("enter profit of items:\n");
for(i=1;i<=n;i++)
scanf("%d",&p[i]);
printf("enter capacity:\n");
scanf("%d",&m);
knapsack(m,n,w,p);
}

