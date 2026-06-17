// User function Template for C++

/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
*/
Node *deleteHead(Node *head) {
    // Your code here
    if(!head || !head->next)
        return nullptr;
    Node* temp=head->next;
    temp->prev=nullptr;
    return temp;
}
