#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode*next;

    ListNode(int x):val(x),next(nullptr){}
};

ListNode* addtwonumbers(ListNode*l1,ListNode*l2){
    ListNode*dummy=new ListNode(0);
    ListNode*temp=dummy;

    int carry=0;
    while(l1!=nullptr||l2!=nullptr||carry!=0){
        int val1=(l1!=nullptr)?l1->val:0;
        int val2=(l2!=nullptr)?l2->val:0;

        int sum=val1+val2+carry;
        carry=sum/10;
        int digit=sum%10;

        temp->next=new ListNode(digit);
        temp=temp->next;
    }
    return dummy->next;
}