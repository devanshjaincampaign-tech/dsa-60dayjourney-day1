#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode*next;

    ListNode(int x): val(x),next(nullptr){}
};

int getDecimalValue(ListNode*head){
    int decimalvalue=0;
    ListNode*curr=head;
    while(curr!=nullptr){
        decimalvalue=decimalvalue*2+curr->val;
        curr=curr->next;

    }
    return decimalvalue;
}
