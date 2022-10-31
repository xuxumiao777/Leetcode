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
    int countNodes(TreeNode* root) {
        TreeNode *current=root;
        int res=0;
        if(root==NULL){
            return 0;
        }
        queue<TreeNode* > q;
        q.push(current);
        while(!q.empty()){
            current=q.front();
            if(current->left!=NULL){
                q.push(current->left);
            }
            if(current->right!=NULL){
                q.push(current->right);
            }
            q.pop();
            res++;
        }
        return res;
    }
};