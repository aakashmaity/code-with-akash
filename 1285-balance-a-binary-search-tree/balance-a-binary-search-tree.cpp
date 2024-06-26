/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBST(int start,int end, vector<int>& v) {
        // sort(v.begin(), v.end());

        // Base Case
        if (start > end)
            return NULL;

        // Get the middle element and make it root
        int mid = (start + end) / 2;
        TreeNode* root = new TreeNode(v[mid]);

        root->left = createBST(start,mid - 1,v);
        root->right = createBST(mid + 1, end,v);

        return root;
    }
    void traverse(TreeNode* root, vector<int>& v) {
        if (root == NULL) {
            return;
        }
        traverse(root->left, v);
        v.push_back(root->val);
        traverse(root->right, v);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        traverse(root, v);

        TreeNode* ans = createBST(0,v.size()-1, v);

        return ans;
    }
};