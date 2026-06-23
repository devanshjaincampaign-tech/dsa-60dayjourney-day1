/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        /*
        THE BRUTE FORCE APPROACH

        vector<int>partition;
        vector<int>lessthanx;
        vector<int>greaterthanx;
        if(!head||!head->next)return head;

        ListNode*curr=head;
        while(curr!=nullptr){
            partition.push_back(curr->val);
            curr=curr->next;
        }
        for(int i:partition){
            if(i<x){
                lessthanx.push_back(i);
            }
            else{
                greaterthanx.push_back(i);
            }
        }
        for(int i=0;i<lessthanx.size();i++){
            partition[i]=lessthanx[i];
        }
        for (int i = 0; i < greaterthanx.size(); i++) {
            partition[lessthanx.size() + i] = greaterthanx[i];
        }

        ListNode*current=head;
        int i=0;
        while(current!=nullptr && i!=partition.size()){
            current->val=partition[i];
            current=current->next;
            i++;
        }
        return head;
        */

       
        ListNode lessHead(0);
        ListNode greaterHead(0);
        
        ListNode* lessTail = &lessHead;
        ListNode* greaterTail = &greaterHead;
        
        ListNode* curr = head;
        while (curr != nullptr) {
            if (curr->val < x) {
                lessTail->next = curr;
                lessTail = lessTail->next;
            } else {
                greaterTail->next = curr;
                greaterTail = greaterTail->next;
            }
            curr = curr->next;
        }
        
        greaterTail->next = nullptr;
        lessTail->next = greaterHead.next;
        
        return lessHead.next;
    }
};