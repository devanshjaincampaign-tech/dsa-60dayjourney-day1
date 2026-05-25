#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode*next;

    ListNode(int x):val(x),next(nullptr){}
};

ListNode* swapPairs(ListNode* head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }

    ListNode*fast=head;
    ListNode*nodex=head;
    ListNode*nodey=head;

    while(fast!=nullptr && fast->next!=nullptr){
        int temp=nodex->val;
        nodex->val=nodey->val;
        nodey->val=temp;

        fast=fast->next->next;
        if(fast!=nullptr){
            nodex=fast;
            nodey=fast->next;
        }
    }
    return head;
}
