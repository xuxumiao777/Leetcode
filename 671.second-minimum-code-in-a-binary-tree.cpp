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
    int findSecondMinimumValue(TreeNode* root) {
        if(root==NULL){
            return -1;
        }
        if(root->left==NULL&&root->right==NULL){
            return -1;
        }
        
        int root_val=root->val;
        queue<TreeNode*> q;
        q.push(root);
        vector<int> Level_val;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode *cur=q.front();
                if(cur->val!=root_val) Level_val.push_back(cur->val);
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
                q.pop();
            }
        }
        if(!Level_val.empty()){
            sort(Level_val.begin(),Level_val.end());
            return Level_val[0];
        }
        return -1;
    }
};