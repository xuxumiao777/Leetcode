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
    int final_sum=0;
    void dfs(TreeNode* cur,int sum){
        if(cur==nullptr){
            return;
        }
        sum=sum*10+cur->val;
        if(cur->left==nullptr&&cur->right==nullptr){
            final_sum+=sum;
        }
        if(cur->left){
            dfs(cur->left,sum);
        }
        if(cur->right){
            dfs(cur->right,sum);
        }
    }
    int sumNumbers(TreeNode* root) {
        dfs(root,0);
        return final_sum;
    }
};