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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            queue<TreeNode*> copy_q(q);
            int flag=0;
            for(int i=0;i<size;i++){
                TreeNode *cur=q.front();
                if(cur->left){
                    flag=1;
                    q.push(cur->left);
                }
                if(cur->right){
                    flag=1;
                    q.push(cur->right);
                }
                
                q.pop();
            }
            if(flag==0){
                return copy_q.front()->val;
            }
            
        }
        return 1;
    }
};