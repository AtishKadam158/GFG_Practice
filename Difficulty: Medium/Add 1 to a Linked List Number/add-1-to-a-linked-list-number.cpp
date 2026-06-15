class Solution {
  public:
    Node* reverse(Node* head){
        Node* prev=nullptr;
        Node* temp=head;
        while(temp){
            Node* t=temp->next;
            temp->next=prev;
            prev=temp;
            temp=t;
        }
        return prev;
    }
    Node* addOne(Node* head) {
        // code here
        head=reverse(head);
        Node *temp=head;
        while(temp){
            if(temp->data<9){
                temp->data++;
                break;
            }
            else
                temp->data=0;
            temp=temp->next;
        }
        head=reverse(head);
        if(!temp){
            Node* x=new Node(1);
            x->next=head;
            head=x;
        }
        return head;
    }
};