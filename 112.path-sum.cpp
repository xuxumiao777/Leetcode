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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==nullptr){
            return false;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* cur=q.front();
                if(cur->left){
                    cur->left->val+=cur->val;
                    q.push(cur->left);
                }
                if(cur->right){
                    cur->right->val+=cur->val;
                    q.push(cur->right);
                }
                if(cur->left==nullptr&&cur->right==nullptr){
                    if(cur->val==targetSum){
                        return true;
                    }
                }
                q.pop();                
            }
            
        }
        return false;
    }
};