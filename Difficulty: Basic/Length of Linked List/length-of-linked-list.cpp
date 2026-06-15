/* Structure of linked list Node
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    int getCount(Node* head) {
        // Code here
        int ct=0;
        while(head && head->next){
            ct+=2;
            head=head->next->next;
        }
        if(head)
            return ct+1;
        return ct;
        
    }
};