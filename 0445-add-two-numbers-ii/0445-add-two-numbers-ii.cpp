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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        stack<int> stk1,stk2;
        
        while(l1){
            stk1.push(l1->val);
            l1=l1->next;
        }
        while(l2){
            stk2.push(l2->val);
            l2=l2->next;
        }
        int carry=0;
        ListNode*prev=NULL;
        while(stk1.size() || stk2.size()){
            int add=0;
            if(stk1.size()){
                add+=stk1.top();
                stk1.pop();
            }
            if(stk2.size()){
                add+=stk2.top();
                stk2.pop();
            }
            add+=carry;
            
            if(add>9)carry=1;
            else carry=0;
            
            ListNode *curr=new ListNode(add%10);
            curr->next=prev;
            prev=curr;
        }
        if(carry){
            ListNode *curr=new ListNode(1);
            curr->next=prev;
            prev=curr;
        }
        return prev;
        
    }
};