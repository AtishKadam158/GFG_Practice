/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution{
public:
    void add_left_child(Node* root, vector<int>& res){
        if(!root) return;
        if(root->left || root->right) res.push_back(root->data);
        if(root->left)
            add_left_child(root->left, res);
        else if(root->right)   
            add_left_child(root->right, res);
    }

    void add_leaf_nodes(Node* root, vector<int>& res){
        if(!root) return;
        if(!root->left && !root->right){
            res.push_back(root->data);
            return; 
        }
        add_leaf_nodes(root->left, res);
        add_leaf_nodes(root->right, res);
    }

    void add_right_child(Node* root, vector<int>& right){
        if(!root) return;
        if(root->left || root->right) right.push_back(root->data);
        if(root->right)
            add_right_child(root->right, right);
        else if(root->left)
            add_right_child(root->left, right);
    }

    vector<int> boundaryTraversal(Node* root){
        vector<int> res;
        vector<int> right;
        if(!root) return res;
        res.push_back(root->data);
        add_left_child(root->left, res);
        add_leaf_nodes(root->left, res);
        add_leaf_nodes(root->right, res);  
        add_right_child(root->right, right);
        for(int i = right.size() - 1; i >= 0; i--){
            res.push_back(right[i]);
        }

        return res;
    }
};