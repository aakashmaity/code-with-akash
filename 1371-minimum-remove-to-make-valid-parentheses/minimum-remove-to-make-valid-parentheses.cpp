class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        stack<int>st;
        unordered_set<int>set;
        string res;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                st.push(i);
            }
            else if(s[i]==')')
            {
                if(st.empty()){
                    set.insert(i);
                }
                else{
                    st.pop();
                }
            }
        }
        
        while(!st.empty()){
            set.insert(st.top());
            st.pop();
        }
        for(int i=0;i<n;i++)
        {
            if(set.find(i)==set.end()){
                res+=s[i];
            }  
        }
        return res;
    }
};