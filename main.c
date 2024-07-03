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
// Display val and there index in a nodeList by travertion
// NOTE: The index was 0 at start of the nodeList | O(n);
void display(Node* node){
    for(int i=0;node!=NULL;node=node->next,i++){
        printf("%d -> %d\n" , i,node->val);
    }
}

// To create a nodeList from a Array of int | O(n);
Node* nodeMaker(int* data,int size){
    Node* ans=(Node*)malloc(sizeof(Node));
    if(allocFailChecker(ans)){printf("Memo Loc Failed");abort();}
    Node* ptr;
    ptr=ans;
    for(int i=0;i<size;i++){

        ptr->val=data[i];
        if(size-i-1){
            ptr->next=(Node*)malloc(sizeof(Node));
            if(allocFailChecker(ptr->next)){printf("Memo Loc Failed");abort();}
            ptr=ptr->next;
        }
    }
    return ans;
}

// Insertion in nodeList 
// at Start | O(1);
int nodeInsertStart(Node* node,int val){
    Node* ans=(Node*)malloc(sizeof(Node));
    if(allocFailChecker(ans)){ printf("Memo Loc Failed");return 1;}
    ans->val=val;
    ans->next=(Node*)malloc(sizeof(Node));
    if(allocFailChecker(ans->next)){ printf("Memo Loc Failed");return 1;}
    *ans->next = *node;
    *node=*ans;
    return 0;
}
// at end | O(n);
int nodeInsertEnd(Node* node,int val){
    Node* ans=(Node*)malloc(sizeof(Node));
    if(allocFailChecker(ans)){ printf("Memo Loc Failed");return 1;}
    ans->val=val;
    for(;node->next!=NULL;node=node->next){
    }
    node->next=ans;
    return 0;
}
// at index | O(n);
int nodeInsertIndex(Node* node,int val,int index){
    Node* ans=(Node*)malloc(sizeof(Node));
    if(allocFailChecker(ans)){ printf("Memo Loc Failed");return 1;}
    ans->val=val;
    for(int i=0;i<index-1;i++,node=node->next){
    }
    ans->next=(Node*)malloc(sizeof(Node));
    if(allocFailChecker(ans->next)){ printf("Memo Loc Failed");return 1;}
    *ans->next=*node->next;
    free(node->next);
    node->next=ans;
    return 0;
}

// Main function | O(n)
int main(void){
    int data[5]={10,20,30,40,50};
    Node* node=nodeMaker((int*)data,5);
    if(node==0) return 0;
    if(nodeInsertStart(node,0) ||
    nodeInsertEnd(node,60) ||
    nodeInsertIndex(node,35,6)){
        return 1;
    }
    display(node);
    free(node);
    return 0;
}