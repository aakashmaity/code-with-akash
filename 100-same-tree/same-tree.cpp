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
    bool ans = true;
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL){
            if(q==NULL){
                return true;
            }
            return false;
        }
        if(q==NULL){
            if(p==NULL){
                return true;
            }
            return false;
        }
        if(p->val != q->val)
            return false;

        ans = ans && isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
        return ans;
    }
};