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
    vector<vector<int>> res;
    void dfs(TreeNode* cur, int remain_sum, vector<int> path){
        if(cur==nullptr){
            return;
        }
        //vector<int> path_new=path;
        path.push_back(cur->val);
        if(cur->left==nullptr&&cur->right==nullptr){
            if(cur->val==remain_sum){
                res.push_back(path);
            }
        }
        if(cur->left){
            dfs(cur->left,remain_sum-cur->val,path);
        }
        if(cur->right){
            dfs(cur->right,remain_sum-cur->val,path);
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        dfs(root,targetSum,path);
        return res;
    }
};