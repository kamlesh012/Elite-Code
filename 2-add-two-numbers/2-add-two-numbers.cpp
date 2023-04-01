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
        ListNode *dummy=NULL;
        ListNode *start=NULL,*prev=NULL;
        int carry=0;
        
        while(l1 && l2){
            int f=l1->val,s=l2->val;
            int add=f+s+carry;
            dummy=new ListNode(add%10);
            if(!start)start=dummy;
            else{
                prev->next=dummy;
            }
            prev=dummy;
            dummy=dummy->next;
            carry=add/10;
            l1=l1->next;
            l2=l2->next;
        }
        
        while(l1){
            int add=l1->val+carry;
            dummy=new ListNode(add%10);
            carry=add/10;
            prev->next=dummy;
            prev=dummy;
            dummy=dummy->next;
            l1=l1->next;
        }
        
        while(l2){
            int add=l2->val+carry;
            dummy=new ListNode(add%10);
            carry=add/10;
            prev->next=dummy;
            prev=dummy;
            dummy=dummy->next;
            l2=l2->next;
        }
        if(carry){
            prev->next=new ListNode(1);
        }
        return start;
    }
};