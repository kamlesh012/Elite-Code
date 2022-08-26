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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL) return head;
        ListNode *temp=head;
        ListNode *prev=new ListNode();
        prev->next=head;
        while(temp!=NULL){
            if(temp->val==val){   
                
                ListNode *del=temp;
                
                prev->next=temp->next;
                temp=temp->next;
                
                if(head==del)head=del->next;
                
                delete(del);
            }
            else{
                temp=temp->next;
                prev=prev->next;
            }
        }
            return head;
    }
};