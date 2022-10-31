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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy=new ListNode(101,head);
        ListNode* cur=dummy;
        while(cur){
            //cout<<cur->val<<endl;
            while(cur->next&&cur->next->val==val){
                cur->next=cur->next->next;
                
            }
            cur=cur->next;
        }
        return dummy->next;
    }
};
