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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if(root==NULL){
            return res;
        }
        q.push(root);
        int level_count=1;
        while(!q.empty()){
            vector<int> level_val;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode *cur=q.front();
                level_val.push_back(cur->val);
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
                q.pop();
            }
            if(level_count%2==0){
                reverse(level_val.begin(),level_val.end());
            }
            cout<<level_count<<endl;
            level_count++;
            res.push_back(level_val);
        }
        return res;
    }
};