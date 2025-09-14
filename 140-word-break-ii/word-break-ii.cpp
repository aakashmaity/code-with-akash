class Solution {
public:
    vector<string> ans;
    unordered_set<string> dict;
    void solve(int i,string s,string currSentence){
        if(i>=s.size()){
            ans.push_back(currSentence);
            return;
        }
        for(int j=i;j<s.length();j++)
        {
            string tempWord = s.substr(i,j-i+1);
            if(dict.count(tempWord))
            {
                string tempSentence = currSentence;

                if(currSentence.length()){
                    currSentence += " ";
                }

                currSentence += tempWord;   // take word
                solve(j+1,s,currSentence);  // explore
                currSentence = tempSentence;  // removed tempWord;
            }
        }

    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        for(string &str : wordDict){
            dict.insert(str);
        }
        string currSentence;
        solve(0,s,currSentence);
        return ans;
    }
};