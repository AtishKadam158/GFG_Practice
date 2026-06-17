/*
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = prev = nullptr;
    }
};
*/

class Solution {
  public:
    Node *insertAtPos(Node *head, int p, int x) {
        // code here
        int a=0;
        Node* temp=head;
        while(temp){
            if(a==p){
                Node* t=new Node(x); 
                t->prev=temp;
                t->next=temp->next;
                if(temp->next)temp->next->prev=t;
                temp->next=t;
                break;
            }
            a++;
            temp=temp->next;
        }
        return head;
    }
};