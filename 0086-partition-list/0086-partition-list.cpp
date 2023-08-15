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
    ListNode* partition(ListNode* head, int x) {
      ListNode *less=NULL,*lesstail=NULL,*more=NULL,*moretail=NULL,*dum=head;
        
        while(dum){
            ListNode *curr=new ListNode(dum->val);
            dum=dum->next;
            if(curr->val<x){
                if(!less){
                    less=curr;
                    lesstail=curr;
                }
                else{
                    lesstail->next=curr;
                    lesstail=curr;
                }
            }
            else{
                if(!more){
                    more=curr;
                    moretail=curr;
                }
                else{
                    moretail->next=curr;
                    moretail=curr;
                }
            }
        }
        
        if(!less)return more;
        lesstail->next=more;
        return less;
    }
};