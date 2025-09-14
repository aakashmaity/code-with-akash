class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mp;

        for(char x: s){
            mp[x]++;
        }

        for(auto x: t){
            if(mp.find(x) != mp.end()){
                mp[x]--;
                if(mp[x] == 0){
                    mp.erase(x);
                }
            }
            else{
                return false;
            }
        }
        if(mp.size() == 0){
            return true;
        }
        return false;
        
    }
};