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
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL){
            
            return true;
        }
        
        ListNode *fast=head,*slow=head;
        while(fast->next!=NULL&&fast->next->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }//now slow is in the middle node
        slow->next=reverseList(slow->next);
        slow=slow->next;
        while(slow){
            if(head->val!=slow->val){
                return false;
            }
            else{
                head=head->next;
                slow=slow->next;
            }
        }
        return true;


    }
    ListNode *reverseList(ListNode *node){
        ListNode *prev=NULL,*next;
        while(node){
            next=node->next;
            node->next=prev;
            prev=node;
            node=next;
            
        }
        return prev;

    }
};
