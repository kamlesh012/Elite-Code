/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *first=head,*second=head;
        if(head)second=head->next;
        while(second!=NULL){
            if(first==second)return true;
            first=first->next;
            if(second)second=second->next;
            if(second)second=second->next;
        }
        return false;
    }
};