class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freq(26,0);
        int n=s.size();
        int m=t.size();
        if(n!=m)
            return false;

        for(int i=0;i<n;i++){
            freq[s[i] - 97]++;
        }
        for(int i=0;i<m;i++){
            freq[t[i] - 97]--;
            
            if(freq[t[i] - 97] < 0){
                return false;
            }
        }
        for(int i=0;i<26;i++){
            if(freq[i]!=0){
                return false;
            }
        }
        return true;
    }
};