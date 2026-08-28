/* Structure of a Tree Node
class Node {
public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    bool isSumProperty(Node *root) {
        if(!root || (!root->left && !root->right))
            return true;
            
        int l= root->left ? root->left->data : 0;
        int r= root->right ? root->right->data : 0;
        
        if(l+r != root->data)   
            return false;
            
        return isSumProperty(root->left) && isSumProperty(root->right);
    }
};