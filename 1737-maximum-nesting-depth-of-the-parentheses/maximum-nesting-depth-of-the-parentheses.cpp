class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;
        int res=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
                st.push('(');
            else if(s[i]==')')
            {
                if(res<st.size())
                    res = st.size();
                st.pop();
            }
        }
        return res;
    }
};