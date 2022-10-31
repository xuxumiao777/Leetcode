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
    void reorderList(ListNode* head) {
        vector<ListNode* > temp;
        ListNode* cur=head;
        int size=0;
        while(cur){
            temp.push_back(cur);
            cur=cur->next;
            size++;
        }
        //cout<<size<<endl;
        //odd number of nodes

        for(int i=0;i<(size/2);i++){
            temp[i]->next=temp[size-1-i];
            temp[size-1-i]->next=temp[i+1];
        }
        temp[size/2]->next=NULL;            

        

    }
};
