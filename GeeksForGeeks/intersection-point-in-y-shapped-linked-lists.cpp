class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        //  Code Here
        Node* a = head1;
        Node* b = head2;
        
        while(a != b) {
            a = a->next;
            b = b->next;
            if(a==NULL) {
                a = head2;
            }
            if(b==NULL) {
                b = head1;
            }
        }
        return a;
    }
};
