#include <stdio.h>
#include <stdlib.h>

void display(int *arr,int index){
    if(index)
        display(arr,index-1);
    printf("%d --> %d \n",index,arr[index]);
}
int linearSearch(int* arr,int num,int maxLen){
    if(!maxLen)
        return -1;
    for(int i=0;i>=0;i++){
        if(arr[i]==num)
            return i;
    }
    return -1;
}
int binarySearch(int* arr,int num,int maxLen){
    if(!maxLen)
        return -1;
    int S=0,E=maxLen-1;
    for(int mid=(S+E)/2;mid!=0 && mid!=maxLen;mid=(S+E)/2){
        if(arr[mid]>num){
            E=mid-1;
        }else if(arr[mid]<num){
            S=mid+1;
        }
        if(arr[mid]==num)
            return mid;
    }
    return -1;
}

int main(){
    int data[10]={1,2,3,4,5,6,7,8,9};
    // display(data,9);
    printf("%d\n",linearSearch(data,9,9));
    printf("%d\n",binarySearch(data,9,9));
    return 0;
}