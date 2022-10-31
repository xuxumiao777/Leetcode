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
    vector<ListNode*> reverseLinkedList(ListNode* head){
        ListNode *pre=NULL;
        ListNode *cur=head;
        ListNode *later;
        vector<ListNode*> base;
        while(cur!=NULL&&cur->next!=NULL){
            later=cur->next;
            cur->next=pre;
            pre=cur;
            cur=later;
        }
        cur->next=pre;
        base.push_back(cur);//head of the new list
        base.push_back(head);
        return base;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int num=0;
        ListNode *dummy=new ListNode(0,head);
        ListNode *cur=dummy;
        while(num<(left-1)){
            cur=cur->next;
            num++;
        }
        ListNode *leftbound=cur->next;
        cur->next=NULL;//cur points to the end of the first part
        ListNode *second=leftbound;
        while(num<right-1){
            second=second->next;
            num++;
        }
        ListNode *rightbound=second->next;
        second->next=NULL;//rightbound points to the start of the third part
        vector<ListNode*> result=reverseLinkedList(leftbound);
        cur->next=result[0];
        result[1]->next=rightbound;
        return dummy->next;

    }
};
