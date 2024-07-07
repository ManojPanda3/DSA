#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    int size,top;
    int* arr;
}stack;

int isEmpty(stack* data){return data->size==0?1:0;}
int isFull(stack* data){return data->size-1==data->top?1:0;}

int push(stack* data,int val){
    if(data->size-1<=data->top){
        printf("ERROR : Stack Overflow\n");
        return 0;
    }
    data->arr[++data->top]=val;
    return 1;
}
int getData(stack* data,int index){
    if(data->size-1<index){
        printf("ERROR : Index Out Of Range\n");
        return -1;
    }
    return data->arr[index];
}
int pop(stack* data){
    if(data->top==0){
        printf("ERROR : aray is empty\n");
        return -1;
    }
    int delData=data->arr[data->top--];
    data->arr[data->top+1]=0;
    return delData;
}
void Display(stack* data){
    for(int i=0;i<data->size;i++){
        printf("%d->%d\t%s\n",i,data->arr[i],i==data->top?"last data ;":"");
    }
}

int main(void){
    stack* data=(stack*)malloc(sizeof(stack));
    data->size=10;
    data->top=-1;
    data->arr=(int*)malloc(sizeof(int)*data->size);
    for(int i = 0; i < 5; i++){
        push(data, i);  // Use push to add elements to the stack
    }
    printf("%d\n",pop(data));
    printf("%d\n",push(data,10));
    printf("%d\n",push(data,10));
    printf("%d\n",push(data,10));
    printf("%d\n",push(data,10));
    printf("%d\n",push(data,10));
    Display(data);
    return 0;
}