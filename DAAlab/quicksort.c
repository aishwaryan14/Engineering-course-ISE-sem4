#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int partition(int *a,int l,int r){
    int temp;
    int p=l;
    int i=l,j=r+1;
   do{
     do{
         i++;
     }while(a[i]<a[p]);
     do{
         j--;   
     }while(a[j]>a[p]);
    if(i<j){
   temp=a[i];
   a[i]=a[j];
   a[j]=temp;
     }
   }while(i<j);
  
      a[l]=a[j];
      a[j]=a[p];
  
  return j;
}

double quicksort(int *a,int l,int r){
int p;
clock_t start=clock();
    if(l<r){
        p=partition(a,l,r);
        quicksort(a,l,p-1);
        quicksort(a,p+1,r);
    }
    return((double)(clock()-start))/CLOCKS_PER_SEC;
}

void main(){
    int n,i;
    double t;
    printf("Enter the size of the array:\n");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        a[i]=rand()%1000;
    }
    t=quicksort(a,0,n-1);
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("time :%f s",t);
}

