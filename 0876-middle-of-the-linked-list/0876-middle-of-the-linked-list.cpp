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
    ListNode* middleNode(ListNode* head) {
        ListNode *frwd=head,*slow=head;
        while(frwd && frwd->next){
            if(frwd->next)frwd=frwd->next;
            if(frwd && frwd->next)frwd=frwd->next;
            slow=slow->next;
        }
        return slow;
    }
};