class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int>mp;
        vector<int>v;
        for(auto i: word)
            mp[i]++;
        for(auto i:mp)
            v.push_back(i.second);
        sort(v.begin(),v.end(),greater<int>());
        int ans=0;
        int k=1;
        int cnt=1;
        for(int i=0;i<v.size();i++)
        {
            if(cnt>8){
                cnt=1;
                k++;
            }
            ans+=v[i]*k;
            cnt++;
        }     
        return ans;
    }
};