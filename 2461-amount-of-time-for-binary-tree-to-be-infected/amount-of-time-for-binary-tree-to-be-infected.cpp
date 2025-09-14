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
    unordered_map<int,vector<int>> AdjList;
    void BuildAdjList(TreeNode* root)
    {
        if(root == NULL )
            return;
        if(root->left)
        {
            AdjList[root->val].push_back(root->left->val);
            AdjList[root->left->val].push_back(root->val);
        }
        if(root->right)
        {
            AdjList[root->val].push_back(root->right->val);
            AdjList[root->right->val].push_back(root->val);
        }

        BuildAdjList(root->left);
        BuildAdjList(root->right);
    }

    int bfs(int s)
    {
        int dist = 0;
        queue<pair<int,int>> q;
        q.push({s,dist});
        set<int> st;
        st.insert(s);
        while(!q.empty())
        {
            pair<int,int> p = q.front();
            q.pop();
            s = p.first;
            int d = p.second;
            for(auto neighbor : AdjList[s])
            {
                // if unvisited
                if(st.count(neighbor) == 0)
                {
                    q.push({neighbor, d+1});
                    dist = max(dist,d+1);
                    st.insert(neighbor);
                }
            }
        }
        return dist;

    }

    int amountOfTime(TreeNode* root, int start) {
        BuildAdjList(root);
        return bfs(start);
    }
};