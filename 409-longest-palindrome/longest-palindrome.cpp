class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>freq;
        for(auto ch: s){
            freq[ch]++;
        }
        int ans=0;
        int f=0;
        for(auto ele : freq){
            if(ele.second%2 == 0){
                ans+=ele.second;
            }
            else{
                ans+=(ele.second-1);
                f=1;
            }
        }
        if(f)
            ans++;
        return ans;
    }
};