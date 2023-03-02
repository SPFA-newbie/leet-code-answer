/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include<stdlib.h>

struct ListNode* createNode(int val){
    struct ListNode* node=malloc(sizeof(struct ListNode));
    node->val=val;
    node->next=NULL;
    return node;
}

int testList(struct ListNode** list, int size) {
    for(int i=0;i<size;i++)
        if(list[i]!=NULL)
            return 1;
    return 0;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    struct ListNode* newList=NULL;
    struct ListNode* now=NULL;
    while(testList(lists, listsSize)==1) {
        int minVal=100000;
        int minPos=-1;
        for(int i=0;i<listsSize;i++)
            if(lists[i]!=NULL && lists[i]->val<minVal)
                minVal=lists[i]->val,
                minPos=i;
        if(newList==NULL) {
            newList=createNode(minVal);
            now=newList;
        }else {
            now->next=createNode(minVal);
            now=now->next;
        }
        lists[minPos]=lists[minPos]->next;
    }
    return newList;
}