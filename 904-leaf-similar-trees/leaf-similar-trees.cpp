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
    void solve(TreeNode* root,vector<int> &leaf)
    {
        if(root->left == NULL && root->right == NULL)
        {
            leaf.push_back(root->val);
            return;
        }
        if(root->left)
            solve(root->left,leaf);
        if(root->right)
            solve(root->right,leaf);

    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) 
    {
        vector<int>seq1,seq2;
        solve(root1,seq1);
        solve(root2,seq2);

        return seq1==seq2;
    }
};