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
    ListNode* reverseList(ListNode* head) {
        //if(head->next=NULL){
            //return head;
        //}
        ListNode *pre=NULL;
        ListNode *cur=head;
        ListNode *fore=NULL;
        while(cur!=NULL){
            fore=cur->next;
            cur->next=pre;
            pre=cur;
            cur=fore;

        }
        return pre;


    }
};