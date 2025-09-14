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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;

        for (vector<int> &node : descriptions) {
            TreeNode* parent = mp.count(node[0]) ? mp[node[0]] : new TreeNode(node[0]);
            TreeNode* child = mp.count(node[1]) ? mp[node[1]] : new TreeNode(node[1]);
            
            if (node[2]) {
                parent->left = child;
            } else {
                parent->right = child;
            }

            mp[node[0]] = parent;
            mp[node[1]] = child;
        }
        for (vector<int> &node : descriptions) {
            mp.erase(node[1]);
        }
        return mp.begin()->second;
    }
};