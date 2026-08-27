/* Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    vector<vector<int>>res;
    void dfs(Node* root,vector<int>&temp){
        if(!root) 
            return;
        temp.push_back(root->data);
        if(!root->left && !root->right)
            res.push_back(temp);
        else{
            dfs(root->left,temp);
            dfs(root->right,temp);
        }
        temp.pop_back();
       
    }
    vector<vector<int>> paths(Node* root) {
        // code here
        vector<int>temp;
        dfs(root,temp);
        return res;
    }
};