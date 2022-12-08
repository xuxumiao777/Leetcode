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
    unordered_map<TreeNode*,int> hashmap;
    int rob(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        if(root->left==NULL&&root->right==NULL){
            return root->val;
        }
        //记忆化搜索
        if(hashmap[root]){
            return hashmap[root];
        }
        //偷当前节点，并且不考虑子节点，而直接考虑孙子节点
        int val1=root->val;
        if(root->left){
            val1+=rob(root->left->left)+rob(root->left->right);
        }
        if(root->right){
            val1+=rob(root->right->left)+rob(root->right->right);
        }
        //不偷当前节点，直接考虑子节点；
        int val2=rob(root->left)+rob(root->right);
        hashmap[root]=max(val1,val2);
        return max(val1,val2);
    }
};