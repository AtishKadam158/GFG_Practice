/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
}; */

class Solution {
  public:
    Node* pre=NULL;
    Node* suc=NULL;
    void find(Node* root,int key){
        if(!root) return;
        if(root->data == key){
            if (root->left != NULL) {
                Node* tmp = root->left;
                while (tmp->right)
                    tmp = tmp->right;
                pre = tmp;
            }
            
            if (root->right != NULL) {
                Node* tmp = root->right;
                while (tmp->left)
                    tmp = tmp->left;
                suc = tmp;
            }
            return;
            
            
        } else if(root->data > key){
            suc =root;
            find(root->left,key);
        }else{
            pre =root;
            find(root->right,key);
        }
    }
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        find(root,key);
        return {pre,suc};
    }
};