#include <iostream>

using namespace std;

struct Listnode{
    int val;
    Listnode*next;

    Listnode(int x):val(x),next(nullptr){}
};

class solution{
    public:
    bool hascycle(Listnode* head){
        Listnode*slow=head;
        Listnode*fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                return true;
            }
        }
        return false;
    }
};