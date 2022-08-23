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
    /*  This Standard Approach is Pending.
    
    ListNode *md=head,*f=head,*last=NULL;
        while(f){
            last=md;
            md=md->next;
            f=f->next;
            if(f)f=f->next;
        }
        ListNode *prev=md,*curr=NULL,*nxt=NULL;
        if(prev && prev->next)curr=prev->next;
        if(curr && curr->next)nxt=curr->next;
        while(curr){
            curr->next=prev;
            prev=curr;
            curr=nxt;
            if(nxt)nxt=nxt->next;
        }
        prev->next=NULL;
        last->next=NULL;
        
        ListNode *strt=head,*strt2=md;
        while(strt && strt2){
            cout<<strt->val<<" "<<strt2->val<<endl;
            if(strt->val!=strt2->val)return false;
            strt=strt->next;
            strt2=strt2->next;
        }
        return true;
        
        */
    
    bool isPalindrome(ListNode* head) {
        string s;
        while (head != NULL) {
            s += head->val;
            head = head->next;
        }

        string t = s;
        reverse(t.begin(), t.end());
        return s == t;
    }
};