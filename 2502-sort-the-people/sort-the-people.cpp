class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<pair<int,string>> v;
        for(int i=0;i<n;i++){
            v.push_back({heights[i],names[i]});
        }
        sort(begin(v),end(v));
        vector<string>ans;

        for(int i=n-1;i>=0;i--){
            ans.push_back(v[i].second);
        }
        return ans;
    }
};