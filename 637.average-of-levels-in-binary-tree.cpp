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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        double level_ave=0;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            level_ave=0;
            for(int i=0;i<size;i++){
                TreeNode *cur=q.front();
                
                level_ave+=cur->val;
                
                
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
                q.pop();
            }
            res.push_back(level_ave/size);
        }
        return res;
    }
};