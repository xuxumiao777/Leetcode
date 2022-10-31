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
    int res=0;
    int find_Height(TreeNode* current){
        if(current==NULL){
            return 0;
        }
        else{
            int L=find_Height(current->left);
            int R=find_Height(current->right);
            res=max(res,L+R+1);
            return max(L,R)+1;
        }
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int temp=find_Height(root);
        return res-1;
    }
};