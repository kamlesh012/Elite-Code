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
    ListNode* sortList(ListNode* head) {
        if(!head)return head;
      vector<int> nodes;
        ListNode *dummy=head;
        
        while(dummy){
            nodes.push_back(dummy->val);
            dummy=dummy->next;
        }
        sort(nodes.begin(),nodes.end());
        ListNode *h=NULL,*tail=NULL;
        
        for(int i=0;i<nodes.size();i++){
            ListNode *curr=new ListNode(nodes[i]);
            if(!i){
                h=curr;
                tail=curr;
            }
            else{
                tail->next=curr;
                tail=curr;
            }
        }
        return h;
        
    }
};