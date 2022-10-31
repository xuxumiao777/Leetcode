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
    bool islesser(TreeNode* root,int val){
        if(root==NULL){
            return true;
        }
        if(root->val<val&&islesser(root->left,val)&&islesser(root->right,val)){
            return true;
        }
        return false;
    }
    bool isgreater(TreeNode* root,int val){
        if(root==NULL){
            return true;
        }
        if(root->val>val&&isgreater(root->left,val)&&isgreater(root->right,val)){
            return true;
        }
        return false;
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        else if(islesser(root->left,root->val)&&isgreater(root->right,root->val)&&isValidBST(root->left)&&isValidBST(root->right)){
            return true;
        }
        return false;
    }
};
