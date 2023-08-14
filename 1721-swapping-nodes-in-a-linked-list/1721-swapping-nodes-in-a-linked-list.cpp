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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<int> nodes;
        ListNode * dum=head;
        while(dum){
            nodes.push_back(dum->val);
            dum=dum->next;
        }
        
        int n=nodes.size();
        
        swap(nodes[k-1],nodes[n-k]);
        
        ListNode *h=NULL,*tail=NULL;
        for(int i=0;i<nodes.size();i++){
            ListNode *curr=new ListNode(nodes[i]);
            if(i==0){
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