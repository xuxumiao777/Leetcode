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
    int max_len=0;
    int find_length(TreeNode* cur){
        if(cur==NULL){
            return 0;
        }
        int left=find_length(cur->left);
        int right=find_length(cur->right);
        int num_left=0,num_right=0;
        if(cur->left&&cur->left->val==cur->val){
            num_left=left+1;
            
        }
        if(cur->right&&cur->right->val==cur->val){
            num_right=right+1;
            
        }
        max_len=max(max_len,num_left+num_right);
        return max(num_left,num_right);
    }

    int longestUnivaluePath(TreeNode* root) {
        max_len=0;
        find_length(root);
        return max_len;
    }
};