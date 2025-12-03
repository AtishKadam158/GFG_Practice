/*
Node is as follows
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int>arr;
    void inorder(Node *root){
        if(!root)return;
        inorder(root->left);
        arr.push_back(root->data);
        inorder(root->right);
    }
    bool findTarget(Node *root, int target) {
        // your code here.
        inorder(root);
        int l=0,r=arr.size()-1;
        while(l<r){
            if(arr[l]+arr[r]==target)
                return true;
            else if(arr[l]+arr[r]>target)
                r--;
            else
                l++;
        }
        return false;
    }
};