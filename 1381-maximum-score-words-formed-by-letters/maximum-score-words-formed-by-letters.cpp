class Solution {
public:
    int maxScore=INT_MIN;
    void solve(int i, int currScore, vector<string>& words, vector<int>& score,vector<int>& freq)
    {
        maxScore = max(maxScore, currScore);
        if(i>=words.size())
            return;
        
        int j=0;
        int tempScore =0;
        vector<int>tempfreq = freq;
        int flag=1;
        while( j<words[i].size() )
        {
            char ch=words[i][j];
            tempfreq[ch-'a']--;
            tempScore += score[ch-'a'];

            if(tempfreq[ch-'a']<0){
                flag=0;
                break;
            }
            j++;
        }
    
        // Take that word
        if(flag)
        {
            solve(i+1,currScore+tempScore,words,score,tempfreq);
        }

        // Not take the word
        solve(i+1,currScore,words,score,freq);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int>freq(26,0);
        for(auto &x : letters)
            freq[x-'a']++;
        
        solve(0,0,words,score,freq); // index, currentScore
        return maxScore;
    }
};