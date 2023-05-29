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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        
        vector<vector<int>> matrix(m,vector<int>(n,-1));
        int startrow=0,endcol=n-1,endrow=m-1,startcol=0;
        while(head){
            for(int i=startcol;head && i<=endcol;i++){
                matrix[startrow][i]=head->val;
                head=head->next;
            }
            startrow++;
            for(int i=startrow;head && i<=endrow;i++){
                matrix[i][endcol]=head->val;
                head=head->next;
            }
            endcol--;
            for(int i=endcol;head && i>=startcol;i--){
                matrix[endrow][i]=head->val;
                head=head->next;
            }
            endrow--;
            for(int i=endrow;head && i>=startrow;i--){
                matrix[i][startcol]=head->val;
                head=head->next;
            }
            startcol++;
        }
        
        return matrix;
    }
};