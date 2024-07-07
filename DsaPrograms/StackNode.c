#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int val;
    struct Node* next;
    struct Node* prev;
}Node;

typedef struct Stack{
    int size,index;
    Node* nodes;
    Node* top;
}Stack;

int isEmpty(Stack* data){return data->size && data->index==-1?1:0;}
int isFull(Stack* data){return data->size<=data->index?1:0;}
int push(Stack* data,int val){
    if(isFull(data)){printf("\n\033[0;0m\033[0;31mError : StackOverflow \033[0m \n");return 0;}
    data->top->next=(Node*)malloc(sizeof(Node));
    Node* tmp = data->top;
    data->top=data->top->next;
    data->index++;
    data->top->prev=tmp;
    data->top->val=val;
    return 0;
};
int pop(Stack* data){
    if(isEmpty(data)){printf("\n\033[0;0m\033[0;31mError : Stack is Empty \033[0m \n");return -1;}
    int* val=(int*)malloc(sizeof(int));
    *val=data->top->val;
    data->top=data->top->prev;
    data->index--;
    free(data->top->next);
    return *val;
};
int peek(Stack* data,int index){
    if(index>data->index){printf("\n\033[0;0m\033[0;31mError : Index out of range \033[0m \n");return -1;}
    Node* ptr=data->top;
    for(int i=0;i<index;i++){
        ptr=ptr->prev;
    }
    return ptr->val;
}
void display(Stack* data){
    for(int i=0;i<=data->index;i++){
        printf("%d->%d\n",i,peek(data,i));
    }
}
int stackTop(Stack* data){
  return data->nodes->val;
}
int stackBottom(Stack* data){
  return data->top->val;
}
int main(void){
    Stack* data=(Stack*)malloc(sizeof(Stack*));
    data->size=10;data->index=0;
    data->nodes=(Node*)malloc(sizeof(Node));
    data->top=data->nodes;
    data->top->val=0;
    for(int i=1;i<10 ;i++){
        push(data,i);
    }
    pop(data);
    display(data);
    printf("%d %d",stackTop(data),stackBottom(data));
    return 0;
}