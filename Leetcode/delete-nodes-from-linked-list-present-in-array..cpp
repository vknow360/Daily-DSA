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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s(nums.begin(), nums.end());
        if(!head) return nullptr;
        
        ListNode* dummy = new ListNode(0, head);

        ListNode* nl = dummy;
        ListNode* tmp = dummy->next;
        while(tmp){
            if(!s.count(tmp->val)){
                nl->next = tmp;
                nl = nl->next;
            }
            tmp = tmp->next;
        }
        nl->next = nullptr;
        return dummy->next;
    }
};