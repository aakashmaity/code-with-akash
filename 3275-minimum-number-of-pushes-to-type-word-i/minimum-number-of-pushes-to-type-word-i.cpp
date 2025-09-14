class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        int p=n/8;
        int r=n%8;
        int i=1,ans=0;;
        while(p)
        {
            ans+=(8*i);
            p--;
            i++;
        }
        ans+=(r*i);
        return ans;
    }
};