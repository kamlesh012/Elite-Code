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
    
    
    int pairSum(ListNode* head) {
        int maxSum=0;
        if(head->next->next==NULL) return (head->val+head->next->val);
        
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast && fast->next){
            slow=slow->next;
            // if(fast->next)fast=fast->next;
            // if(fast->next)fast=fast->next;
            fast=fast->next->next;
        }
        // cout<<slow->val<<endl;
        ListNode *head2 = Reverse(slow);
        
        // ListNode *it=head2;
        // while(it!=NULL){
        //     cout<<it->val<<" ";
        //     it=it->next;
        // }
        // ListNode *it2=head;
        // while(it2!=NULL){
        //     cout<<it2->val<<" ";
        //     it2=it2->next;
        // }
        
        while(head2){
            int sum=head->val+head2->val;
            maxSum=max(maxSum, sum);
            head=head->next;
            head2=head2->next;
        }
        return maxSum;
    }
};