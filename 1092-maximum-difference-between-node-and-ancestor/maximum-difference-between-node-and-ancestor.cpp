/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root,int mini,int maxi,int &ans)
    {
        if(!root)
            return;
        
        maxi = max(maxi,root->val);
        mini = min(mini,root->val);
        ans = max(ans,maxi-mini);

        solve(root->left,mini,maxi,ans);
        solve(root->right,mini,maxi,ans);
        
    }

    int maxAncestorDiff(TreeNode* root) {
        int mini,maxi;
        int ans=0;
        mini=maxi=root->val;
        solve(root,mini,maxi,ans);
        return ans;
    }
};