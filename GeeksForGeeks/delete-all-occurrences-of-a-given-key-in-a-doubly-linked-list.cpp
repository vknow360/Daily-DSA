class Solution {
public:
    void deleteAllOccurOfX(Node** head_ref, int x) {

        while (*head_ref && (*head_ref)->data == x) {
            Node* temp = *head_ref;
            *head_ref = (*head_ref)->next;
            delete temp;
        }

        if (*head_ref)
            (*head_ref)->prev = NULL;

        Node* curr = *head_ref;
        while (curr) {
            if (curr->data == x) {
                Node* nextNode = curr->next;

                if (curr->prev)
                    curr->prev->next = curr->next;
                if (curr->next)
                    curr->next->prev = curr->prev;

                delete curr;
                curr = nextNode;
            } else {
                curr = curr->next;
            }
        }
    }
};
