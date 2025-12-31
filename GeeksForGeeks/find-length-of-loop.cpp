/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        Node* slow = head;
        Node* fast = head;
        
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            if(fast == slow) break;
        }
        
        if(fast == nullptr || fast->next == nullptr) return 0;
        
        int count = 0;
        
        do {
            slow = slow->next;
            count++;
        }while(fast != slow);
        
        return count;
    }
};
