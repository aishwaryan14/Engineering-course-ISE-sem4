#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void bubblesort(int *a,int n){
    int i,j,temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}

void main(){
    int i,n;
    clock_t start,end;
    printf("ENter the size of the array:\n");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        a[i]=rand()%1000;
    }
    start=clock();
    bubblesort(a,n);
    end=clock();
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    double t;
    t=((double)(end-start))/CLOCKS_PER_SEC;
    printf("Time taken:%fs\n",t);
}

