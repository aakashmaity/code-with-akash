class Solution {
public:
    int countTriplets(vector<int>& arr) {
        vector<int>prefixXor(arr.begin(),arr.end());

        prefixXor.insert(prefixXor.begin(), 0);
        int n = prefixXor.size();

        // for(int i=0;i<n;i++)
        //     cout<<prefixXor[i]<< " ";

        for(int i=1;i<n;i++)
        {
            prefixXor[i] ^= prefixXor[i-1];
        }

        int triplets = 0;
        for(int i=0;i<n;i++)
        {   
            for(int k=i+1;k<n;k++)
            {
                if(prefixXor[k] == prefixXor[i])
                    triplets += (k-i-1); 
            }
        }
        return triplets;
    }
};