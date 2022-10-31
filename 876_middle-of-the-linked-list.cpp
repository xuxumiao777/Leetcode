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
    ListNode* middleNode(ListNode* head) {
        ListNode* cur=head;
        int size=0;
        while(cur){
            size++;
            cur=cur->next;
        }
        //cout<<size<<endl;
        for(int i=0;i<size/2;i++){
            head=head->next;
        }
        return head;
    }
};
