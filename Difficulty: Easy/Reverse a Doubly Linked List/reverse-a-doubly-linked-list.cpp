/* Structure of doubly linked list node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        Node* h=head;
        Node* prev=nullptr;
        while(h){
            Node* temp=h->next;
            swap(h->prev,h->next);
            prev=h;
            h=temp;
        }
        return prev;
    }
};