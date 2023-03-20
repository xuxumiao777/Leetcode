/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        TreeNode* search_left=root;
        TreeNode* search_right=root;
        queue<TreeNode*> q_left;
        queue<TreeNode*> q_right;
        q_left.push(search_left);
        q_right.push(search_right);
        while(!q_left.empty()&&!q_right.empty()){
            search_left=q_left.front();
            search_right=q_right.front();
            if(search_left->right!=NULL&&search_right->left!=NULL){
                q_left.push(search_left->right);
                q_right.push(search_right->left);
            }
            else if(search_left->right!=NULL||search_right->left!=NULL){
                return false;
            }
            if(search_left->left!=NULL&&search_right->right!=NULL){
                q_left.push(search_left->left);
                q_right.push(search_right->right);
            }
            else if(search_left->left!=NULL||search_right->right!=NULL){
                return false;
            }
            int temp1=search_left->val;
            q_left.pop();
            int temp2=search_right->val;
            q_right.pop();
            if(temp1!=temp2){
                return false;
            }            
        }
        if(q_left.empty()&&q_right.empty()){
            return true;
        }
        return false;
    }
};
//review
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool check(TreeNode* p, TreeNode* q){
        if(p==nullptr&&q==nullptr){
            return true;
        }
        else if(p==nullptr||q==nullptr){
            return false;
        }
        if(p->val==q->val){
            return check(p->left,q->right)&&check(p->right,q->left);
        }
        else{
            return false;
        }
    }
    bool isSymmetric(TreeNode* root) {
        return check(root,root);
    }
};