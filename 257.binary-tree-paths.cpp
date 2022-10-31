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
    vector<string> res;
    void dfs(TreeNode* cur,string &str){
        if(cur->left==nullptr&&cur->right==nullptr){
            str.append("->");
            str+=to_string(cur->val);
            res.push_back(str);
            //cout<<1<<endl;
        }

        //str.append("->");
        //str.push_back('0'+cur->val);
        if(cur->left){
            string left_str=str;
            left_str.append("->");
            left_str+=to_string(cur->val);
            dfs(cur->left,left_str);
        }
        if(cur->right){
            string right_str=str;
            right_str.append("->");
            right_str+=to_string(cur->val);
            dfs(cur->right,right_str);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string s;
        dfs(root,s);
        for(auto &str:res){
            str.erase(0,2);
        }
        return res;
    }
};