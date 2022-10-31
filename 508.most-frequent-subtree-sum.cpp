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
    vector<int> res;
    vector<int> res2;
    unordered_map<int,int> hashmap;
    int dfs(TreeNode* current){
        if(current==NULL){
            return 0;
        }
        int temp=dfs(current->left)+dfs(current->right)+current->val;
        res.push_back(temp);
        return temp;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        
        
        dfs(root);
        int max=0;
        for(auto res_ele:res){
            hashmap[res_ele]++;
            if(hashmap[res_ele]>max){
                max=hashmap[res_ele];
            }
        }
        for(auto res_ele:res){
            if(hashmap[res_ele]==max){
                res2.push_back(res_ele);
                hashmap[res_ele]=0;
            }
            
        }
        return res2;
    }
};