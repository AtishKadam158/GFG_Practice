/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    int findMaxFork(Node* root, int k) {
        // code here
        if(!root) return -1;
        if(root->data==k)
            return root->data;
        else if (root->data > k)
            return findMaxFork(root->left,k);
        else
            return max(root->data,findMaxFork(root->right,k));
    }
};