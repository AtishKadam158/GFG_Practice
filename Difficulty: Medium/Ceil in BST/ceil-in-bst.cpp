class Solution {
  public:
    int c=INT_MAX;
    int findCeil(Node* root, int x) {
        // code here
        if(!root) return -1;
        if(root->data == x)
            return root->data;
        else if(root->data<x)
            return findCeil(root->right,x);
        else{
            c=min(c,root->data);
            int l =findCeil(root->left,x);
            return l != -1 ? min(c,l) : c;
        }
    }
};
