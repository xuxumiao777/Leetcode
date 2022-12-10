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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head){
            return head;
        }
        ListNode *dummy=new ListNode(101,head);
        ListNode *cur=dummy;
        while(cur->next!=NULL&&cur->next->next!=NULL){
            if(cur->next->val==cur->next->next->val){
                int x=cur->next->val;
                while(cur->next!=NULL&&cur->next->val==x){
                    cur->next=cur->next->next;
                    
                }
                //cur=cur->next;
            }
            else{
                cur=cur->next;
            }
        }
        return dummy->next;

    }
};