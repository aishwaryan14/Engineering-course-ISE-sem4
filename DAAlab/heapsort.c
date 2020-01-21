#include<stdio.h>
#include<math.h>
#include<time.h>

int heapify(int h[50],int n)
{
 int i,j,n1,k,heap,v;
 n1=n;
 for(i=n/2;i>=1;i--)
 {
  
  while((2*i)<=n1)
  {
   j=2*i;
   if(j<n1)
   {
     if(h[j]<h[j+1])
      j=j+1;
    }
   if(h[i]>=h[j])
      break;//go to next iteration
   else 
   {
    //swap
    k=h[i];
    h[i]=h[j];
    h[j]=k;
   }
 }
}
}

void main()
{
 int i,n,size,t;
 int h[50];
 int upper=1000,lower=0;
 clock_t start,end;
 double time_taken;
 printf("Enter the no of elements:\n");
 scanf("%d",&n);
 printf("The elements to be sorted\n");
 for(i=1;i<=n;i++)
 {
   h[i]=(rand()%(upper-lower+1))+lower;
   printf("%d ",h[i]); 
  }
  start=clock();
  //Insertion
  heapify(h,n);
  printf("\nElements heapified \n");
  for(i=1;i<=n;i++)
   printf("%d \t",h[i]);
  //Deletion
  for(i=n;i>=1;i--)
  {
   t=h[1];
   h[1]=h[i];
   h[i]=t;
   size=i-1;
    heapify(h,size);
  }
  end=clock();
 printf("\nRotated elements are: \n");
 for(i=1;i<=n;i++)
  printf("%d \t",h[i]);
 time_taken=(double)(end-start)/CLOCKS_PER_SEC;
 printf("Time taken:%f",time_taken);
}

