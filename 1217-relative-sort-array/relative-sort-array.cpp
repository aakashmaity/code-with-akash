class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        vector<int> freq(1001,0);
        for(int i=0;i<n;i++){
            freq[arr1[i]]++;
        }
        vector<int>ans;
        for(int i=0;i<m;i++)
        {
            while(freq[arr2[i]]--){
                ans.push_back(arr2[i]);
            }
        }
        for(int i=0;i<1001;i++){
            if(freq[i]>0){
                while(freq[i]--){
                    ans.push_back(i);
                }
            }
        }
        return ans;
    }
};