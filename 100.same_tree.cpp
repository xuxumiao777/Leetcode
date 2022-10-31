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
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        TreeNode *p_current=p;
        TreeNode *q_current=q;
        queue<TreeNode*> queue_p;
        queue<TreeNode*> queue_q;
        queue_p.push(p_current);
        queue_q.push(q_current);
        if(p==NULL&&q==NULL){
            return true;
        }
        if(p==NULL&&q!=NULL){
            return false;
        }
        if(p!=NULL&&q==NULL){
            return false;
        }
        while(!queue_p.empty()&&!queue_q.empty()){
            p_current=queue_p.front();
            q_current=queue_q.front();
            if(p_current->val!=q_current->val){
                return false;
            }
            if(p_current->left!=NULL&&q_current->left!=NULL){
                queue_p.push(p_current->left);
                queue_q.push(q_current->left);
            }
            else if(p_current->left!=NULL||q_current->left!=NULL){
                return false;
            }
            if(p_current->right!=NULL&&q_current->right!=NULL){
                queue_p.push(p_current->right);
                queue_q.push(q_current->right);
            }
            else if(p_current->right!=NULL||q_current->right!=NULL){
                return false;
            }
            queue_p.pop();
            queue_q.pop();
        }
        return true;
    }
};