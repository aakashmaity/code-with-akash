class Solution {
public:
    void solve(string path,stack<string> &st,int i,int n)
    {
        if(i>=n)
            return;
        if(path[i]!='/')
        {
            string str="";
            while(i<n && path[i]!='/')
            {
                str+=path[i];
                i++;
            }
            if(str=="..")
            {
                if(!st.empty())
                {
                    st.pop();
                }
            }
            else if(str != ".")
            {
                st.push(str);
            }
        }
        solve(path,st,i+1,n);
    }
    string simplifyPath(string path) {
        stack<string> st;
        int n = path.size();
        solve(path,st,0,n);
        string ans="";
        while(!st.empty())
        {
            ans="/"+st.top()+ans;
            st.pop();
        }
        if(ans.size()!=0)
            return ans;
        else
            return "/";
    }
};