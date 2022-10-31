#include <cstddef>
#include <stdio.h>
#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//bool is_empty(ListNode*);
void print_list(ListNode*);
//bool is_empty(ListNode* temp)

void print_list(ListNode* temp)
{
    if (is_empty(temp)==false)
    {   
         cout<<"here temp(head)"<<temp->next<<endl;
         while(temp!=NULL)
         {
            cout<<temp->val<<endl;
            temp = temp->next;
         }
    }
}
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p=l1;
        ListNode* q=l2;
        int len1=1;
        int len2=1;
        if(p->next!=NULL){
             len1++;
             p=p->next;
        }
        if(q->next!=NULL){
             len2++;
             q=q->next;
        }
        if(len1<len2){
             for(int i=0;i<len2-len1;i++){
                 p->next=new ListNode(0);
                 p=p->next;
             }
        }
        if(len2<len1){
             for(int i=0;i<len1-len2;i++){
                 q->next=new ListNode(0);
                 q=q->next;
             }
        }
        int count=0;
        p=l1;
        q=l2;
        ListNode* l_out=new ListNode(-1);
        ListNode* s=l_out;       
        int t=0;
        while(p!=NULL&&q!=NULL){
            t=count+p->val+q->val;
            s->next=new ListNode(t%10);
            count=t/10;
            s=s->next;
            p=p->next;
            q=q->next;
        }
        if(count)//若最后还有进位
        {
            s->next=new ListNode(1);
            //s=s->next;
        }        
        return l_out->next;
    }
};
int main(){
    //ListNode* l1=[];
    ListNode * head = NULL;
    ListNode * second = NULL;
    ListNode * third = NULL;

    head = new ListNode();
    second = new ListNode();
    third = new ListNode();

    head->val = 1;
    head->next = second;

    second->val = 2;
    second->next = third;

    third->val = 3;
    third->next = NULL;

    print_list(head);
    return 0;
}