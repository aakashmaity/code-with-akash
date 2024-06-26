class Solution {
public:
    int heightChecker(vector<int>& heights) {
         // counting sort variant 
        int freq[101]={0};
        for(int x: heights) freq[x]++;
        int cnt=0, ans=0;
        for (int x=1; x<=100; x++){
            int f=freq[x];
            for(int i=cnt; i<cnt+f; i++)
                ans+=heights[i]!=x;
            cnt+=f;
        }
        return ans;
    }
};