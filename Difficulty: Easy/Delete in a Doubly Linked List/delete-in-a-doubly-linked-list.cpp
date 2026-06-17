/* Structure of Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class Solution {
  public:
    Node* delPos(Node* head, int x) {
        // code here
        int a=1;
        Node* h=head;
        while(h){
            if(a==x){
                if(h->prev)
                    h->prev->next=h->next;
                if(h->next)
                    h->next->prev=h->prev;
                if(h == head)
                    head = head->next;
                delete h;
                return head;
            }
            a++;
            h=h->next;
        }
        return head;
    }
};