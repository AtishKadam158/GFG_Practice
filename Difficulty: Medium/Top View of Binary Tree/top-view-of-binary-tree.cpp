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
    vector<int> topView(Node *root) {
        // code here
        if(!root)return {};
        map<int,vector<int>>mp;
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            pair<Node*,int>temp=q.front();
            int col=temp.second;
            Node* ptr=temp.first;
            q.pop();
            if(ptr->left) q.push({ptr->left,col-1});
            if(ptr->right) q.push({ptr->right,col+1});
            mp[col].push_back(ptr->data);
        }
        vector<int>res;
        for(auto itr:mp){
            res.push_back(itr.second[0]);
        }
        return res;
    }
};