/*
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  private:
    Node* reverse(Node* head) {
        Node* prev = NULL;
        while (head) {
            Node* nxt = head->next;
            head->next = prev;
            prev = head;
            head = nxt;
        }
        return prev;
    }

    Node* removeLeadingZeros(Node* head) {
        while (head && head->data == 0) {
            head = head->next;
        }
        return head;
    }

  public:
    Node* addTwoLists(Node* head1, Node* head2) {
        head1 = removeLeadingZeros(head1);
        head2 = removeLeadingZeros(head2);

        if (!head1 && !head2) return new Node(0);

        head1 = reverse(head1);
        head2 = reverse(head2);

        Node* dummy = new Node(-1);
        Node* curr = dummy;
        int carry = 0;

        while (head1 || head2 || carry) {
            int sum = carry;
            if (head1) {
                sum += head1->data;
                head1 = head1->next;
            }
            if (head2) {
                sum += head2->data;
                head2 = head2->next;
            }

            carry = sum / 10;
            curr->next = new Node(sum % 10);
            curr = curr->next;
        }

        Node* ans = reverse(dummy->next);

        return ans;
    }
};
