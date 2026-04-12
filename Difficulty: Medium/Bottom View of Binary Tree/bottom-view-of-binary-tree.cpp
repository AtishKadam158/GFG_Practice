/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        // code here
        if(!root) return {};
        queue<pair<Node* ,int>>q;
        map<int,int>mp;
        q.push({root,0});
        while(!q.empty()){
            pair<Node*,int>temp=q.front();
            q.pop();
            Node* ptr=temp.first;
            int col=temp.second;
            if(ptr->left) q.push({ptr->left,col-1});
            if(ptr->right) q.push({ptr->right,col+1});
            mp[col]=ptr->data;
        }
        vector<int>res;
        for(auto itr : mp){
            res.push_back(itr.second);
        }
        return res;
    }
};