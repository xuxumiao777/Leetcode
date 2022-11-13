/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int mmax_len=0;
    int maxDepth(Node* root) {
        if(root==NULL){
            return 0;
        }
        int size=root->children.size();
        int temp=1;
        for(int i=0;i<size;i++){
            int temp_loop=maxDepth(root->children[i])+1;
            temp=max(temp,temp_loop);
            if(temp>mmax_len){
                mmax_len=temp;
            }
        }
        return temp;
    }
};