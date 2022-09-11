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
    ListNode* Reverse(ListNode* slow){
        ListNode *prev=NULL;
        ListNode *curr=slow;

        while(curr){
             
            ListNode *nxt=curr->next;      
            curr->next=prev;
            prev=curr;
            curr=nxt;
            
        }
        
        return prev;
    }
    
    
    bool isPalindrome(ListNode* head) {
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode *head2 = Reverse(slow);
        ListNode *temp=head;
        bool ok=true;
        while(head2!=NULL){
            if(temp->val!=head2->val){ok=false;break;}
            temp=temp->next;
            head2=head2->next;
        }
        return ok;
    }
};