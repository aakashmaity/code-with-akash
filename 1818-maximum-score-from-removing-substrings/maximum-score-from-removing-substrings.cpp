class Solution {
public:
    void solve(string& s, int point, string str, stack<char>& st, int& score) {
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (!st.empty() && st.top() == str[0] && s[i] == str[1]) {
                score += point;
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
    }
    int maximumGain(string s, int x, int y) {
        int greater = 0;
        int lower = 0;
        string str1;
        if (x >= y) {
            greater = x;
            str1 = "ab";
            lower = y;
        } else {
            greater = y;
            str1 = "ba";
            lower = x;
        }
        int score = 0;
        stack<char> st;

        // calculate greater point possible
        solve(s, greater, str1, st, score);

        string s1;
        while(!st.empty()){
            s1+=st.top();
            st.pop();
        }
        stack<char> temp;
        // possible score from the remaining
        solve(s1,lower,str1,temp,score);
        
        return score;
    }
};