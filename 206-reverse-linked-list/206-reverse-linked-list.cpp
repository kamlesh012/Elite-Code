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
    ListNode* reverseList(ListNode* head) {
        if(!head)return head;
        ListNode *frwd=head->next;
        ListNode *curr=head;
        ListNode *prev=NULL;
        while(curr){
            curr->next=prev;
            prev=curr;
            curr=frwd;
            if(frwd)
                frwd=frwd->next;
        }
        return prev;
    }
};