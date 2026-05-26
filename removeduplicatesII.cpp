class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || head->next == nullptr) return head;

        // PHASE 1: Clean up the head if it starts with duplicates
        while (head != nullptr && head->next != nullptr && head->val == head->next->val) {
            int duplicate_value = head->val;
            while (head != nullptr && head->val == duplicate_value) {
                ListNode* temp = head; // Fixed: Assigning node pointer, not value
                head = head->next;
                delete temp;
            }
        }
        
        // Safety check: If the entire list consisted of duplicates, head is now nullptr
        if (!head || head->next == nullptr) return head;

        // PHASE 2: Process the rest of the list
        ListNode* prev = head;
        ListNode* curr = head->next;

        while (curr != nullptr) {
            // Fixed: Added safety check for curr->next before reading its value
            if (curr->next != nullptr && curr->val == curr->next->val) {
                int duplicate_val = curr->val;
                
                while (curr != nullptr && curr->val == duplicate_val) {
                    ListNode* temp = curr;
                    curr = curr->next;
                    delete temp; // Fixed: Delete the stored 'temp', not the advanced 'curr'
                }
                // Fixed: Link the stable 'prev' node to the updated 'curr' position
                prev->next = curr; 
                
                // Note: We don't advance 'prev' here because 'curr' needs to be 
                // evaluated by the main loop condition first.
            } 
            else {
                // No duplicate found; safely move both pointers forward
                prev = curr;
                curr = curr->next;
            }
        }
        
        return head;
    }
};