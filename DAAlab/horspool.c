#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int table[128];//bad shift table
int count=0;//count the no of shifts
void shifttable(char *pattern){
    int i;
    int l=strlen(pattern);
    for(i=0;i<128;i++){
        table[i]=l;
    }
    for(i=0;i<l-1;i++)
    {
       table[pattern[i]]=l-i-1;
     } 
}

int horspool(char *str,char *pattern){
 int i,j,k,l;
 int flag=1;
 l=strlen(pattern);
 shifttable(pattern);
 i=l-1;
 while(i<strlen(str)){
     k=0;
     while(k<l && str[i-k]==pattern[l-k-1]){
         k++;
     }
     if(k==l){
         return i-l+2;
     }
     else{
         i+=table[str[i]];
         count++;
     }
 }
    return -1;
}

void main(){
    char str[50],pattern[50];
    int pos;
    printf("Enter the string:\n");
    scanf("%s",str);
    printf("Enter the pattern:\n");
    scanf("%s",pattern);
    pos=horspool(str,pattern);
    if(pos==-1){
        printf("pattern not found\n");
    }
    else{
        printf("Pattern found at pos:%d after shifts:%d",pos,count);
    }
}

