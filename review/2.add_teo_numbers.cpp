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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* head=l1;
        int temp=0;
        while(l1->next!=nullptr&&l2->next!=nullptr){
            temp=l1->val+l2->val;
            l1->val=(temp+carry)%10;
            carry=(temp+carry)/10;
            l1=l1->next;
            l2=l2->next;            
        }
        temp=l1->val+l2->val+carry;
        l1->val=temp%10;
        carry=temp/10;
        //return head;
        if(l1->next==nullptr){
            l1->next=l2->next;
            while(l2->next){
                //cout<<"there";
                temp=carry+l2->next->val;
                l1->next->val=temp%10;
                l1=l2->next;
                carry=temp/10;
                l2=l2->next;
            }
        }
        else{
            //cout<<"here";
            while(l1->next){
                temp=carry+l1->next->val;
                l1->next->val=temp%10;
                carry=temp/10;
                l1=l1->next;
            }
        }
        if(l1->next==nullptr&&l2->next==nullptr&&carry!=0){
            l1->next=new ListNode(carry);
        }
        return head;
    }
};