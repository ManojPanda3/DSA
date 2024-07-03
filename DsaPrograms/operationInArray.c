#include <stdio.h>
#include <stdlib.h>

void display(int *arr,int index){
    if(index)
        display(arr,index-1);
    printf("%d --> %d\n",index,arr[index]);
}
int insert(int *arr,int num, int len , int maxLen , int index){
    if(len>=maxLen)
        return -1;
    for(int i=len-1;i>=index;i--){
        arr[i+1]=arr[i];
    }
    arr[index]=num;
    return 0;
}
int del(int *arr, int len , int maxLen , int index,int mode){
    if(len==0)
        return -1;
    if(mode==1)
    {
        for(int i=index;i<maxLen;i++)
            arr[i]=arr[i+1];
    }
    else if(mode==0)
    {
        arr[index]=arr[len-1];
        arr[len-1]=0;
    }else;
    return 0;
}
int main(){
    int arr[10]={12,22,33,10};
    printf("%s %s\n",insert(arr,2,4,10,2)?"Not":"","Successful");
    display(arr,4);
    printf("%s %s\n",del(arr,5,10,2,1)?"Not":"","Successful");
    display(arr,5);
    return 0;
}