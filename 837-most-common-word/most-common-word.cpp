class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        int n=paragraph.size();
        map<string,int>mp;
        string temp;
        for(int i=0;i<n;i++){
            char ch = tolower(paragraph[i]);
            if((ch >= 'a' && ch <= 'z')){
                temp+=ch;
            }
            else if(!temp.empty()){
                mp[temp]++;
                temp="";
            }
        }

        if (!temp.empty()) {
            mp[temp]++;
        }
        for (string b : banned) {
            mp[b] = 0;
        }

        string ans="";
        int freq=0;
        for(auto a: mp){
            cout<<a.first<<" "<<a.second<<endl;
            if(a.second > freq){
                freq=a.second;
                ans=a.first;
            }
        }
        return ans;
    }
};