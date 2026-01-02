class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head->next) return nullptr;

        ListNode* fast = head;
        ListNode* slow = new ListNode(0);
        slow->next = head;
        ListNode* prev = NULL;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;

        return head;
    }
};
