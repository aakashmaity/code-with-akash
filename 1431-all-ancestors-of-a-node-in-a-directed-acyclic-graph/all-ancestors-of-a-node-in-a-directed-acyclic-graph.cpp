class Solution {
public:
    void DFS(int u, unordered_map<int, vector<int>> &adjList, vector<bool> &visited){
        visited[u]=true; 

        for(int &v : adjList[u]){
            if(visited[v] != true){
                DFS(v,adjList,visited);
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> result;
        unordered_map<int, vector<int>> adjList;

        // creating AdjList 
        for (vector<int> vec : edges) {
            int u = vec[0];
            int v = vec[1];

            adjList[v].push_back(u);  // v->u
        }
        
        // find out all ancestors of each node,  5-> 0,1,3
        for(int u=0;u<n;u++){
            vector<int>ancestors;
            vector<bool> visited(n,false);
            DFS(u,adjList,visited);

            
            for(int i=0;i<n;i++){
                if(i == u)   // skip 0->0 ,1->1,...
                    continue;

                if(visited[i]==true){
                    ancestors.push_back(i);
                }
            }
            result.push_back(ancestors);
        }
        return result;
    }
};