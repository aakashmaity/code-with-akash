class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string res=strs[0];
        for(int i=1;i<n;i++)
        {
            string str=strs[i];
            string st;
            for(int j=0;j<str.size();j++)
            {
                if(str[j]==res[j])
                {
                    st+=str[j];
                }
                else
                    break;
            }
            if(st.size()<res.size())
                res=st;
            if(res=="")
                return "";
        }
        return res;
    }
};