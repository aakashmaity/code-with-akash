class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n=s.size();
        vector<int>left(n,-1);
        vector<int>right(n,-1);

        int idx=-1;
        for(int i=n-1;i>=0;i--){
            if(s[i]==c){
                idx=i;
            }
            right[i]=idx;
        }
        idx=-1;
        for(int i=0;i<n;i++){
            if(s[i]==c){
                idx=i;
            }
            left[i]=idx;
        }

        vector<int>ans;
        
        for(int i=0;i<n;i++){
            int ld=i-left[i];
            int rd=right[i]-i;

            if(left[i]==-1){
                ans.push_back(rd);
            }
            else if(right[i]==-1){
                ans.push_back(ld);
            }
            else{
                ans.push_back(min(ld,rd));
            }
        }
        return ans;
    }
};