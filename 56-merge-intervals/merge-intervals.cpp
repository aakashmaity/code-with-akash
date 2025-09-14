class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        unordered_map<int,int> mp;
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<n;i++)
        {
            int f=1;
            for(auto x:mp)
            {
                if(intervals[i][0]<=x.second){
                    int s=x.first;
                    int e=max(x.second,intervals[i][1]);
                    mp.erase(x.first);
                    mp[s]=e;
                    f=0;
                    break;
                }
            }
            if(f)
                mp[intervals[i][0]]=intervals[i][1];
        }
        vector<vector<int>> ans;
        for(auto x: mp)
        {
            cout<<x.first<<" ";
            ans.push_back({x.first,x.second});
        }
        return ans;
    }
};