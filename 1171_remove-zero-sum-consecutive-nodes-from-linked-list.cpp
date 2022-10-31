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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int,ListNode*> hashmap;
        ListNode *dummy=new ListNode(0,head);//since head can be deleted
        int sum=0;
        for(auto cur=dummy;cur;cur=cur->next){
            sum+=cur->val;
            cout<<sum<<endl;
            hashmap[sum]=cur;
        }
        sum=0;
        for(auto cur=dummy;cur;cur=cur->next){
            sum+=cur->val;
            
            cur->next=hashmap[sum]->next;//如果重复位置就是自己指向自己，如果hashmap[sum]==0这段C++会自动跳过
            

        }
        return dummy->next;        


    }
};
//前缀和与hashmap
