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
    bool isPalindrome(Node *head) {
        //  code here
        if(!head || !head->next) return true;
        Node* slow = head;
        Node* fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        Node* tmp = slow;
        Node* rev = NULL;
        while(tmp) {
            Node* next = tmp->next;
            tmp->next = rev;
            rev = tmp;
            tmp = next;
        }
        
        tmp = head;
        Node* revTmp = rev;
        while(tmp && revTmp) {
            if(tmp->data != revTmp->data) return false;
            tmp = tmp->next;
            revTmp = revTmp->next;
        }
        return true;
    }
};
