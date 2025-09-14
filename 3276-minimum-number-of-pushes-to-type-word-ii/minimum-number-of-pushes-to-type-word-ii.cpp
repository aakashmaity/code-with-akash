class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(27,0);
        for(char ch : word){
            freq[ch - 'a']++;
        }
        sort(begin(freq),end(freq), greater<int>());

        int ans=0;
        int level=1,count=1;

        int i=0;
        while(freq[i] != 0){
            if(count > 8){   // 2 to 9 mapping
                count = 1;
                level++;
            }
            ans += freq[i]*level;
            count++;
            i++;
        }
        return ans;

    }
};