class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        map<int,int>mp;
        stack<int>st;

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums2[i] > st.top()){
                st.pop();
            }

            if(st.empty()){
                mp[nums2[i]] = -1;
            }
            else{
                mp[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }

        vector<int> ans;
        for(int x: nums1){
            if(mp.find(x) != mp.end()){
                ans.push_back(mp[x]);
            }
            else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};