class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int s = edges.size();
        vector<vector<int>> adjList(s+2);

        for(auto edge : edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        int n = adjList.size()-1; //as 0 cann't be a node
        for(int i=0;i<=n;i++){
            if(adjList[i].size()==n-1){
                return i;
            }
        }
        return -1;
    }
};