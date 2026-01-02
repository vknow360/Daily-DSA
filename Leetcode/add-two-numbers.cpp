class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(0);
        ListNode* resHead = res;
        int carry = 0;
        int sum = l1->val+l2->val;
        carry = sum/10;
        res->val = sum%10;
        l1 = l1->next;
        l2 = l2->next;
        while(l1 && l2) {
            int sum = l1->val+l2->val+carry;
            carry = sum/10;
            l1 = l1->next;
            l2 = l2->next;
            res->next = new ListNode(sum%10);
            res = res->next;
        }

        while(l1) {
            int sum = l1->val+carry;
            carry = sum/10;
            l1 = l1->next;
            res->next = new ListNode(sum%10);
            res = res->next;
        }

        while(l2) {
            int sum = l2->val+carry;
            carry = sum/10;
            l2 = l2->next;
            res->next = new ListNode(sum%10);
            res = res->next;
        }

        if(carry > 0) {
            res->next = new ListNode(carry);
            res = res->next;
        }

        return resHead;
    }
};
