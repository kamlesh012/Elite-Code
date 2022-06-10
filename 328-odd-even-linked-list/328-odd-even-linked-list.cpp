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
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr || head->next==nullptr || head->next->next==nullptr)return head;
        ListNode *o=head,*e=head->next,*evenhead=head->next;
        
        while(e!=nullptr && e->next!=nullptr){
            if(o->next!=nullptr){
                cout<<o->val<<" odd  ";
                o->next=o->next->next;
            }
            if(e->next!=nullptr){
                cout<<e->val<<" even ";
                e->next=e->next->next;
            }
            e=e->next;
            o=o->next;
        }
        if(o!=nullptr)o->next=evenhead;
        return head;
        
    }
};