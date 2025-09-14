class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n = matches.size();
        unordered_map<int,int>mp;
        vector<vector<int>>ans;
        vector<int>v1,v2;
        set<int>st;
        for(int i=0;i<n;i++)
        {
            mp[matches[i][1]]++;
        }
        for(auto ele:mp)
        {
            if(ele.second==1){
                v2.push_back(ele.first);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(mp.find(matches[i][0])==mp.end())
            {
                v1.push_back(matches[i][0]);
                mp[matches[i][0]]++;
            }
                
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        ans.push_back(v1);
        ans.push_back(v2);
        return ans;
    }
};