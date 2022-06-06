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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *dum1=headA;
        ListNode *dum2=headB;
        int n=0,m=0;
        while(dum1){
            n++;
            dum1=dum1->next;
        }
        while(dum2){
            m++;
            dum2=dum2->next;
        }
        if(n<m){
            int diff=m-n;
            int cnt=0;
            dum2=headB;
            while(cnt<diff){
                dum2=dum2->next;
                cnt++;
            }
            dum1=headA;
            while(dum1!=dum2)
                {dum1=dum1->next;
                dum2=dum2->next;}
            return dum1;
        }
        else{
            int diff=n-m;
            int cnt=0;
            dum1=headA;
            while(cnt<diff){
                dum1=dum1->next;
                cnt++;
            }
            dum2=headB;
            while(dum1!=dum2)
                {dum1=dum1->next;
                dum2=dum2->next;}
            return dum2;
        }
    }
};