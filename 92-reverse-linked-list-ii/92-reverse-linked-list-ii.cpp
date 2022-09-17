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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(head==NULL || head->next==NULL) return head;
        
        ListNode *dummy = new ListNode(-1);
        
        dummy->next=head;
        
        ListNode *temp=dummy;
        
        ListNode *prevTemp=NULL;
        int tl=left;
        // while(left--){
        while(tl--){
            
            prevTemp=temp;
            
            temp=temp->next;   
            
        }
        
        // cout<<temp->val;
        
        ListNode *prevR=prevTemp;
        // cout<<prevR->val<<endl;
        
        ListNode *currR=temp;
        // cout<<currR->val<<endl;
        
//         ListNode*prevR=temp;
        
//         ListNode *currR=temp->next;
        
        for(int i=left;i<=right;i++)
        {
            if(currR)
            {
                ListNode *forwR=currR->next;
                
                currR->next=prevR;
                prevR=currR;
                currR=forwR;
            }
        }
        
        // cout<<prevR->val;
        prevTemp->next=prevR;
        
        temp->next=currR;
        
        return dummy->next;
    }
};