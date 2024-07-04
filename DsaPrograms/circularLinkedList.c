// CircularNodeList
#include <stdio.h>
#include <stdlib.h>

// defineing node list in C
typedef struct ListNode
{
    int val;
    struct ListNode* next;
}Node;

// allocFailChecker
int allocFailChecker(Node* data){
    if(data==NULL){
        return 1;
    };
    return 0;
}
// Print all the available element in a Circular Linked List
void cirNodeDisplay(Node* node,int size){
    int i=0;
    for(;i<size;i++,node=node->next){
        printf("%d -> %d\n",i,node->val);
    }
    printf("%d<->0 -> %d\n",i,node->val);
}

// Create a Circular Linked list from the provided array nd return it
Node* makeCircularLinkList(int* data,int size){
    Node* ans=(Node*)malloc(sizeof(Node*));
    if(allocFailChecker(ans)){abort();}
    Node* ptr;
    ptr=ans;
    for(int i=0;i<size;i++){
        ptr->val=data[i];
        if(size-i-1){
        ptr->next=(Node*)malloc(sizeof(Node*));
        if(allocFailChecker(ptr->next)){abort();}
        ptr=ptr->next;}
    }
    ptr->next=ans;
    return ans;
}

Node* cirLinkListInsertStart(Node* node,int val){
    Node* ans=(Node*)malloc(sizeof(Node*));
    ans->next=(Node*)malloc(sizeof(Node*));
    ans->val=val;
    *ans->next = *node;
    *node=*ans;   
}
Node* cirLinkListInsertEnd(Node* node,int val){
    Node* ans=(Node*)malloc(sizeof(Node*));
    ans->next=(Node*)malloc(sizeof(Node*));
    ans->val=val;
    *ans->next = *node;
    *node=*ans;  
}
Node* cirLinkListInsertIndex(Node* node,int size,int val,int index){
    Node* ans=(Node*)malloc(sizeof(Node*));
    ans->next=(Node*)malloc(sizeof(Node*));
    ans->val=val;
    for(int i=0;i<index%size-1;i++){node=node->next;}
    *ans->next=*node->next;
    node->next = ans;
}
// Main function | O(n)
int main(void){
    int data[5] = {10,20,30,40,50};
    Node* node= makeCircularLinkList((int*)data,5);
    cirLinkListInsertStart(node,0);
    cirLinkListInsertEnd(node,60);
    cirLinkListInsertIndex(node,7,60,3);
    cirNodeDisplay(node,8);
    return 0;
}