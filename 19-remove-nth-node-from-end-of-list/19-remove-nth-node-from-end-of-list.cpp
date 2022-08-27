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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL)return NULL;
        ListNode *tmp=head,*slow=NULL;
        
        //Find Length of LL
        int cnt=0;
        while(tmp!=NULL){
            tmp=tmp->next;
            cnt++;         
        }
        tmp=head;
        cnt-=n; //cnt will now store cnt-nth number from start.
        
        if(cnt==0)return head->next;        //edge case
        while(cnt--){
            slow=tmp;
            tmp=tmp->next;      //move to cnt-nth node from start
        }
        
        slow->next=tmp->next;  
        tmp=NULL;
        
        return head;
        
    }
};