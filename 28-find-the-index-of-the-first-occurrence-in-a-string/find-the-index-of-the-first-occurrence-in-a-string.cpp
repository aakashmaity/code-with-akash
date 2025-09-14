class Solution {
public:
    int strStr(string haystack, string needle) {
        int n1=haystack.size();
        int n2=needle.size();
        for(int i=0;i<n1;i++)
        {
            string temp=haystack.substr(i,n2);
            if(temp==needle)
                return i;
        }
        return -1;
    }
};