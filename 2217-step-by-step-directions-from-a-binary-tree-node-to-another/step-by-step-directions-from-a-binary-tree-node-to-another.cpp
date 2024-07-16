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
    TreeNode* lowestCommonAncestor(TreeNode* root, int src, int dest){
        if(!root){
            return NULL;
        }

        if(root->val == src || root->val == dest){
            return root;
        }

        TreeNode* l = lowestCommonAncestor(root->left, src, dest);
        TreeNode* r = lowestCommonAncestor(root->right, src, dest);

        if(l && r){
            return root;
        }

        return l ? l : r;
    } 
    bool findPath(TreeNode* LCA, string &path, int target){
        if(LCA == NULL){
            return false;
        }

        if(LCA->val == target){
            return true;
        }

        path.push_back('L');
        if(findPath(LCA->left,path,target)){
            return true;
        }
        path.pop_back();

        path.push_back('R');
        if(findPath(LCA->right,path,target)){
            return true;
        }
        path.pop_back();

        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* LCA = lowestCommonAncestor(root,startValue,destValue);

        string lcaTosrc = "";
        string lcaTodest = "";

        findPath(LCA,lcaTosrc,startValue);
        findPath(LCA,lcaTodest,destValue);

        string ans;
        for(int i=0;i<lcaTosrc.size();i++){
            ans+= "U";
        }
        ans+=lcaTodest;

        return ans;
    }
};