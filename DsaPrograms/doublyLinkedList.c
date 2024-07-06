// DoublyLinkedList
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// defineing node list in C
typedef struct DoublyLinkedList
{
    struct DoublyLinkedList* prev;
    int val;
    struct DoublyLinkedList* next;
}DoublyNode;

// allocFailChecker
int allocFailChecker(DoublyNode* data){
    if(data==NULL){
        return 1;
    };
    return 0;
}
void display(DoublyNode* node){
    for(int i=0;node!=NULL;i++){
        printf("%d -> %d\n",i,node->val);
        printf("curr -> %p \n",node);
        printf("prev -> %p \n",node->prev);
        printf("next -> %p \n\n",node->next);        
        node=node->next;
    }
}
DoublyNode* makeDoublyLinkedList(int* data,int size){
    DoublyNode* ans=(DoublyNode*)malloc(sizeof(DoublyNode*));
    DoublyNode* ptr,*prev;
    ptr=ans;
    if(allocFailChecker(ans)){printf("Malloc Failed to locate memory");abort();}
    for(int i=0;i<size;i++){
        ptr->val=data[i];
        ptr->prev=prev;
        if(size-i-1)
        {
            ptr->next=(DoublyNode*)malloc(sizeof(DoublyNode*));
            if(allocFailChecker(ptr->next)){printf("Malloc Failed to locate memory");abort();}
            prev=ptr;
            ptr=ptr->next;
        }
    }
    return ans;
}
DoublyNode* insertStartDoublyLinkedList(DoublyNode* node,int val){
    DoublyNode* ans=(DoublyNode*)malloc(sizeof(DoublyNode*));
    ans->next=(DoublyNode*)malloc(sizeof(DoublyNode*));
    ans->val=val;
    *ans->next = *node;
    *node=*ans;
    node->next->prev=node;  
    node->next->next->prev=node->next;
}
DoublyNode* insertEndDoublyLinkedList(DoublyNode* node,int val){
    DoublyNode* ans=(DoublyNode*)malloc(sizeof(DoublyNode*));
    ans->val=val;
    while(node->next!=NULL){
        node=node->next;
    }
    node->next=ans;
    ans->prev = node;
}
DoublyNode* insertIndexDoublyLinkedList(DoublyNode* node,int val,int index){
    DoublyNode* ans=(DoublyNode*)malloc(sizeof(DoublyNode*));
    ans->next=(DoublyNode*)malloc(sizeof(DoublyNode*));
    ans->val=val;
    for(int i=0;i<index-1;i++){
        node=node->next;
    }
    *ans->next=*node->next;
    ans->next->prev = ans;
    node->next=ans;
    ans->prev = node;
}
// Main function | O(n)
int main(void){
    int data[5] = {10,20,30,40,50};
    DoublyNode* node= makeDoublyLinkedList((int*)data,5);
    insertStartDoublyLinkedList(node,0);
    insertEndDoublyLinkedList(node,0);
    insertIndexDoublyLinkedList(node,0,3);
    display(node);
    return 0;
}