/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;

        Node* dummy = new Node(0);
        Node* tempC = dummy;
        Node* temp = head;
        while(temp){
            Node* a = new Node(temp->val);
            tempC->next = a;
            tempC = tempC->next;
            temp = temp->next;
        }

        Node* tempa = head;
        Node* tempb = dummy->next;;

        while(tempa){
            mp[tempa] = tempb;
            tempa = tempa->next;
            tempb = tempb->next;
        }

        for(auto& [a , b] : mp){
            if(a->random){
                b->random = mp[a->random];
            }
        }
        return dummy->next;
    }
};