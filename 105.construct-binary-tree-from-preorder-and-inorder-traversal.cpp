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
    unordered_map<int,int> index_map;
    TreeNode* tree_from_inorder_preorder(vector<int>& preorder,vector<int>& inorder,int preorder_left,int preorder_right,int inorder_left,int inorder_right){
        if(preorder_left>preorder_right||inorder_left>inorder_right){
            return nullptr;
        }
        TreeNode* head=new TreeNode(preorder[preorder_left]);
        int inorder_pos=index_map[head->val];
        int left_subtree_len=inorder_pos-inorder_left+1;
        head->right=tree_from_inorder_preorder(preorder,inorder,preorder_left+left_subtree_len,preorder_right,inorder_pos+1,inorder_right);
        head->left=tree_from_inorder_preorder(preorder,inorder,preorder_left+1,preorder_left+left_subtree_len,inorder_left,inorder_pos-1);
        return head;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            index_map[inorder[i]]=i;
        }
        return tree_from_inorder_preorder(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }
};