#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int *a,int l,int mid,int h){
    int p=mid-l;//size of left array
    int q=h-mid;//size of right array
    int b[p],c[q];
    int i,j,k=l;
    //copy elements to left array and right array
    for(i=0,j=l;j<mid;i++,j++){
        b[i]=a[j];
    }
    for(i=0,j=mid;j<h;i++,j++){
        c[i]=a[j];
    }
    i=0,j=0;
    //merge
    while(i<p && j<q){
        if(b[i]<c[j]){
            a[k++]=b[i++];
        }
        else{
            a[k++]=c[j++];
        }
    }
    //copy rest of the elements
    while(i<p){
        a[k++]=b[i++];
    }
    while(j<q){
        a[k++]=c[j++];
    }
}
double mergeSort(int *a,int l,int h){
   int mid=(l+h)/2;
   clock_t start=clock();
    if(h-l > 1){
        mergeSort(a,l,mid);
        mergeSort(a,mid,h);
        merge(a,l,mid,h);}
    return((double)(clock()-start))/CLOCKS_PER_SEC;
}

void main(){
    int n,i;
    printf("Enter the size of the array:\n");
    scanf("%d",&n);
    int a[n];
    int lower=0,upper=1000;
    for(i=0;i<n;i++){
        a[i]=(rand()%(upper-lower +1))+lower;
    }
    double t;
    t=mergeSort(a,0,n);
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("Time: %fs",t);
}

