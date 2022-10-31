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
    ListNode* reverseList(ListNode* head){
        ListNode *pre=NULL;
        ListNode *cur=head;
        ListNode *later=head->next;
        while(cur&&cur->next){
            cur->next=pre;
            pre=cur;
            cur=later;
            later=later->next;
        }
        cur->next=pre;
        return cur;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l11=reverseList(l1);
        
        ListNode* l22=reverseList(l2);
        ListNode* head=new ListNode();
        ListNode* cur=head;

        
        int carry=0;
        int sum=0;
        while(l11||l22){
            int num1=l11?l11->val:0;
            int num2=l22?l22->val:0;
            int sum=carry+num1+num2;
            cur->next=new ListNode(sum%10);
            carry=sum/10;
            if(l11) l11=l11->next;
            if(l22) l22=l22->next;
            cur=cur->next;
        }
        if(carry) cur->next=new ListNode(carry);
        ListNode* res=reverseList(head->next);
        return res;
    }
};
