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
    
    //Recursive Solution
    ListNode *nhead=NULL;
    ListNode *rec(ListNode *head){
        if(!head || head->next==NULL){
            //Keep the new head on the last node.
            nhead=head;
            return head;
        }
        ListNode * curr=rec(head->next);//move recursive call to next node
        
        curr->next=head;    //point the head of next node(returned from recursion) to current.
        
        head->next=NULL;       //set current's next to null.
        
        return head;
    }
    
    ListNode* reverseList(ListNode* head) {
        
        if(!head)return head;
        rec(head);
        return nhead;
        
        //Iterative Solution
        
        // ListNode *frwd=head->next;
        // ListNode *curr=head;
        // ListNode *prev=NULL;
        // while(curr){
        //     curr->next=prev;
        //     prev=curr;
        //     curr=frwd;
        //     if(frwd)
        //         frwd=frwd->next;
        // }
        // return prev;
    }
};