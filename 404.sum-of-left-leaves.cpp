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
    int sum_left=0;
    void dfs(TreeNode* cur){
        if(cur==nullptr){
            return;
        }
        if(cur->left&&cur->left->left==nullptr&&cur->left->right==nullptr){
            sum_left+=cur->left->val;
            //return;
        }
        if(cur->left){
            dfs(cur->left);
        }
        if(cur->right){
            dfs(cur->right);
        }

    }
    int sumOfLeftLeaves(TreeNode* root) {
        dfs(root);
        return sum_left;
    }
};