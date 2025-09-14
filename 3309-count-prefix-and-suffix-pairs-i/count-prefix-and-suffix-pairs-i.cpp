class Solution {
public:
    int isPrefixAndSuffix(vector<string>& words, int i,int j)
    {
        string s1 = words[i];
        string s2 = words[j];
        int s=0,s2l=s2.size(),s1l=s1.size();
        while(s<s1.size())
        {
            if(s1[s] != s2[s])
                return 0;
            if(s1[s] != s2[s2l-s1l+s])
                return 0;
            s++;
        }
        return 1;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(words[i].size() <= words[j].size()){
                    cnt+=isPrefixAndSuffix(words,i,j);
                }
            }
        }
        return cnt;
    }
};