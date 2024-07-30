class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        stack<char>st;

        int ans=0;
        int i=0;
        while(i<n){
            if(!st.empty() && st.top()=='b' && s[i]=='a'){
                ans++;
                st.pop();
            }
            else{
                st.push(s[i]);
            }
            i++;    
        }
        return ans;
    }
};