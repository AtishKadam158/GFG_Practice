/*
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    pair<int,int> help(Node* root){
        if(!root) return {0,0};
        pair<int,int>l=help(root->left);
        pair<int,int>r=help(root->right);
        int both_child=max(l.first, l.second) + max(r.first, r.second);;
        int no_child=root->data+l.second+r.second;
        return {no_child,both_child};
    }
    int getMaxSum(Node *root) {
        // code here
        pair<int,int>p =help(root);
        return max(p.first,p.second);
    }
};