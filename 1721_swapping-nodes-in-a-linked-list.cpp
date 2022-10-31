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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* dummy=new ListNode(0,head);
        int size=0;
        ListNode* front;
        while(head){
            if(size+1==k){
                front=head;
            }
            head=head->next;
            size++;

        }

        head=dummy->next;
        while(size-k){
            head=head->next;
            size--;
        }
        ListNode* back=head;
        int temp=back->val;
        back->val=front->val;
        front->val=temp;
        return dummy->next;

    }
};
