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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* cur=head;
        int num=0;
        while(cur){
            num++;
            cur=cur->next;
        }
        num = num - n;
        cur=head;
        if(num==0){
            return head->next;
        }
        while(num-1){
            cur=cur->next;
            num--;
        }
        cur->next = cur->next->next;

        return head;
    }
};