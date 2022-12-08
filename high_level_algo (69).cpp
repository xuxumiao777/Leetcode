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
    int mres=0;
    int GetSum(TreeNode* current){
        if(current==NULL){
            return 0;
        }
        int Sum_left=GetSum(current->left);
        int Sum_right=GetSum(current->right);
        mres+=abs(Sum_left-Sum_right);
        return Sum_left+Sum_right+current->val;
    }
    int findTilt(TreeNode* root) {        
        GetSum(root);
        return mres;
        
    }
};