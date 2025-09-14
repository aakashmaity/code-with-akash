class Solution {
public:
    int check(string output)
    {
        vector<int>freq(26,0);
        for(auto i: output)
        {
            if(freq[i-'a']!=0){
                return 0;
            }
            freq[i-'a']++;
        }
        return output.size();
    }
    void solve(vector<string>& arr,int i,string output,int &ans)
    {
        if(i>=arr.size())
            return;
        
        //exclude 
        solve(arr,i+1,output,ans);

        
        output+=arr[i];
        int res=check(output);
        ans=max(ans,res);
        //include
        if(res)
            solve(arr,i+1,output,ans);
    }
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        int ans=0;
        string output="";
        solve(arr,0,output,ans);
        return ans;
    }
};