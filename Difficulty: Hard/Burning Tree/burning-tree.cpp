/* Structure of binary tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    Node* dfs(Node* root,int target){
        if (!root) return nullptr;

        if (root->data == target)
            return root;
    
        Node* left = dfs(root->left, target);
        if (left) return left;
    
        Node* right = dfs(root->right, target);
        if (right) return right;
    
        return nullptr;
    }
    int minTime(Node* root, int target) {
        // code here
        Node* tar=dfs(root,target);
        queue<Node*>q;
        q.push(root);
        unordered_map<Node*,Node*>mp;
        
        while(!q.empty()){
            Node* tmp=q.front();
            q.pop();
            if(tmp->left){
                q.push(tmp->left);
                mp[tmp->left]=tmp;
            }
            if(tmp->right){
                q.push(tmp->right);
                mp[tmp->right]=tmp;
            }
            
        }
        
        q.push(tar);
        unordered_map<Node*,bool>visi;
        visi[tar]=1;
        int dist=0;
        
        while(!q.empty()){
            int sz=q.size();
            bool burned = false;
            while(sz--){
                Node* tmp=q.front();
                q.pop();
                if(tmp->left && !visi.count(tmp->left)){
                    q.push(tmp->left);
                    visi[tmp->left]=1;
                    burned = true;
                }
                if(tmp->right && !visi.count(tmp->right)){
                    q.push(tmp->right);
                    visi[tmp->right]=1;
                    burned = true;
                }
                if(mp[tmp] && !visi.count(mp[tmp])){
                    q.push(mp[tmp]);
                    visi[mp[tmp]]=1;
                    burned = true;
                }
            }
            if(burned)
                dist++;
        }
        return dist;
    }
};