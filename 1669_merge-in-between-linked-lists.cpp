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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        //need two pointers(one in a-1;one in b+1)
        ListNode* cur_front=list1;
        //int iteration=a-1;
        for(int iteration=a-1;cur_front&&iteration>0;iteration--){
            cur_front=cur_front->next;
        }
        ListNode* cur_behind=cur_front->next;
        cur_front->next=list2;
        while(list2->next){
            list2=list2->next;
        }
        for(int iteration=b-a+1;iteration>0;iteration--){
            cur_behind=cur_behind->next;
        }
        list2->next=cur_behind;        
        return list1;
        
    }
};
