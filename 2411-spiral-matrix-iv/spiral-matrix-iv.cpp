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
    int M,N;
    void solve(ListNode* root,vector<vector<int>> &ans,int top, int right, int bottom, int left){
        if(root == NULL){
            return;
        }

        int i=left;
        while(i<=right && root != NULL){
            ans[top][i] = root->val;
            root = root->next;
            i++;
        }
        top++;

        i=top;
        while(i<=bottom && root != NULL){
            ans[i][right] = root->val;
            root = root->next;
            i++;
        }
        right--;

        i=right;
        while(i>=left && root != NULL){
            ans[bottom][i] = root->val;
            root = root->next;
            i--;
        }
        bottom--;

        i=bottom;
        while(i>=top && root != NULL){
            ans[i][left] = root->val;
            root = root->next;
            i--;
        }
        left++;

        solve(root,ans,top,right,bottom,left);
    }
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        M=m;
        N=n;
        vector<vector<int>> ans(m, vector<int>(n,-1));

        solve(head, ans,0,n-1,m-1,0);  // top,right,bottom,left
        return ans;
    }
};