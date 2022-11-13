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
    TreeNode* maximum_index(int start,int end,vector<int>& nums){
        if(start>end){
            return NULL;
        }
        int res=nums[start];
        int best=start;
        for(int i=start;i<=end;i++){
            if(nums[i]>res){
                res=nums[i];
                best=i;
            }
        }
        TreeNode* root=new TreeNode(nums[best]); 
        root->left=maximum_index(start,best-1,nums);
        root->right=maximum_index(best+1,end,nums);

        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        return maximum_index(0,nums.size()-1,nums);
    }
};