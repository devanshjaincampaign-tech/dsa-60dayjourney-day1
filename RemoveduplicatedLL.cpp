#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        while (curr != nullptr && curr->next != nullptr) {
            if (curr->val == curr->next->val) {
                ListNode* next_node = curr->next->next;
                delete curr->next;
                curr->next = next_node;
            }
            else {
                curr = curr->next;
            }
        }
        return head;
    }
};

void printList(ListNode* head) {
    ListNode* curr = head;
    while (curr != nullptr) {
        std::cout << curr->val;
        if (curr->next != nullptr) {
            std::cout << " -> ";
        }
        curr = curr->next;
    }
    std::cout << std::endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);

    std::cout << "Original List: ";
    printList(head);

    Solution solution;
    head = solution.deleteDuplicates(head);

    std::cout << "Cleaned List:  ";
    printList(head);

    ListNode* curr = head;
    while (curr != nullptr) {
        ListNode* nextNode = curr->next;
        delete curr;
        curr = nextNode;
    }

    return 0;
}