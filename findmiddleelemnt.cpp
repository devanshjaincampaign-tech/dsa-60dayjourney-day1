#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode*next;

    ListNode(int x): val(x),next(nullptr){}
};

class solution{
    public:
     ListNode* middleNode(ListNode* head){
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
     }
};
