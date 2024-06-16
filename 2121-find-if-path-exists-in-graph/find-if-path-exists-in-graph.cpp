class Solution {
public:
    bool dfs(int src, int dest, vector<vector<int>> &g, unordered_set<int> &visited){
        if(src == dest)
            return true;
        
        visited.insert(src);
        bool ans = false;
        for(auto neighbour : g[src]){
            if(visited.find(neighbour)==visited.end()){
                ans = ans || dfs(neighbour,dest,g,visited);
            }
        }
        return ans;
    }
    bool validPath(int n, vector<vector<int>>& edges, int src, int dest) {
        vector<vector<int>> g(n);

        for(int i=0;i<edges.size();i++){
            int u =edges[i][0];
            int v =edges[i][1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        unordered_set<int>visited;
        return dfs(src,dest,g,visited);
    }
};