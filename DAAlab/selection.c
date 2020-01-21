#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void Selectionsort(int *a,int n){
    int i,j,small,temp;

    for(i=0;i<n-1;i++)
    {
        small=i;
       for(j=i+1;j<n;j++){
           if(a[j]<a[small]){
               small=j;
           }
       }
       temp=a[i];
       a[i]=a[small];
       a[small]=temp;
     }
}
void main()
{
    int i,n;
    double t;
    clock_t start,end;
    printf("Enter the size of the array:\n");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        a[i]=rand()%1000;
    }
    start=clock();
    Selectionsort(a,n);
    end=clock();
    t=((double)(end-start))/CLOCKS_PER_SEC;
    for(i=0;i<n;i++){
     printf("%d ",a[i]);   
    }
    printf("time taken:%fs\n",t);
   
}

