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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int n = descriptions.size();
        unordered_map<int, TreeNode*> mp;
        unordered_set<int> st;

        for (vector<int>& node : descriptions) {
            int parent = node[0];
            int child = node[1];
            int side = node[2];

            TreeNode* temp;
            // parent
            if (!mp.count(parent)) {
                TreeNode* newNode = new TreeNode(parent);
                mp[parent] = newNode;
                temp = newNode;
            } else {
                temp = mp[parent];
            }

            // child
            if (!mp.count(child)) {
                if (side) { // Left
                    temp->left = new TreeNode(child);
                    mp[child] = temp->left;
                } else { // Right
                    temp->right = new TreeNode(child);
                    mp[child] = temp->right;
                }
            } else {
                TreeNode* ch = mp[child];
                if(side){
                    temp -> left = ch;
                }
                else{
                    temp->right = ch;
                }
            }
            st.insert(child);
        }

        TreeNode *ans = NULL;
        for(vector<int>& node : descriptions){
            if(!st.count(node[0])){
                ans = mp[node[0]];
                break;
            }
        }
        return ans;
    }
};