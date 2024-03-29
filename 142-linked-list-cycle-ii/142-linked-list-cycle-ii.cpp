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
    //Well Known Standard Algorithm
    //States that: Suppose m is the point where our fast & slow pointers meet.
    
    //If we travel from head & m in forward direction then they will meet at the point where cycle begins in a Linked List.
    
    ListNode *detectCycle(ListNode *head) {
        
        //O(N) Time & Space Complexity
        unordered_set<ListNode*> s;
        while(head){
            if(s.find(head)!=s.end()){
                return head;
            }
            else{
                s.insert(head);
            }
            head=head->next;
        }
        return NULL;
        
        //O(N) Time & O(1) Space Complexity
        
//         ListNode *start=head,*slow=head,*fast=head;
//         while(fast && fast->next){
//             fast=fast->next;
//             slow=slow->next;
//             if(fast)fast=fast->next;
            
//             if(slow==fast){
//                 while(start!=fast){
//                     start=start->next;
//                     fast=fast->next;
//                 }
//                 return start;
//             }
//         }
//         return NULL;
    }
};