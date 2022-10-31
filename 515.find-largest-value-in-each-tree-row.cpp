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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        
        queue<TreeNode*> q;
        if(root==NULL){
            return res;
        }
        q.push(root);
        //res.push_back(root->val);
        int level_val;
        while(!q.empty()){
            level_val=INT_MIN;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode *cur=q.front();
                level_val=max(level_val,cur->val);
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
                q.pop();

            }
            
            res.push_back(level_val);
        }
        return res;
    }
};