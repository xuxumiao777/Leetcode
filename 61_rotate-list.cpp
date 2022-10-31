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
    ListNode* rotateRight(ListNode* head, int k) {
        int size=0;
        ListNode *cur=head;
        while(cur&&cur->next){
            size++;
            cur=cur->next;
        }
        size++;
        //cout<<size<<endl;
        int rotation_times=k%size;
        if(rotation_times==0){
            return head;
        }
        ListNode *cur2=head;
        for(int i=0;i<(size-rotation_times-1);i++){
            cur2=cur2->next;

        }
        ListNode *part2_head=cur2->next;
        cur2->next=NULL;
        cur->next=head;
        return part2_head;

    }
};
