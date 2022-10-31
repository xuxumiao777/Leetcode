/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int size=0;
        ListNode* cur=head;
        vector<ListNode*> res;
        while(cur){
            size++;
            cur=cur->next;
        }
        //cout<<size<<endl;
        cur=head;
        int interation=0;
        int num=size;
        //ListNode *node_start=new ListNode(101,cur);
        ListNode *node_start=cur;
        for(int i=0;i<k;i++){
            cur=node_start;
            //it contains num/k+1 nodes
            if(num%k){
                num--;
                interation=size/k;
                while(interation&&cur){
                    cur=cur->next;
                    interation--;
                }
                if(cur){
                    ListNode *temp=cur->next;
                    cur->next=NULL;
                    res.push_back(node_start);
                    node_start=temp;
                }
                // else{
                //     res.push_back(node_start);                    
                // }



            }

            //it contains num/k nodes
            else if(num%k==0){
                
                interation=size/k-1;
                //cout<<interation<<endl;
                while(interation&&cur){
                    cur=cur->next;
                    interation--;
                }
                if(cur){
                    //cout<<cur->val<<endl; 
                    ListNode *temp=cur->next;
                    cur->next=NULL;
                    res.push_back(node_start);
                    node_start=temp;
                    //cout<<node_start->val<<endl;
                }
                else{
                    res.push_back(node_start);
                    //cout<<node_start->val<<endl;                    
                }
            }
        }
        return res;

    }
};
