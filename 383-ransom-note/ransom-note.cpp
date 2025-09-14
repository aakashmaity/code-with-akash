class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mp;
        for(int i=0;i<ransomNote.size();i++)
        {
            mp[ransomNote[i]]++;
        }
        for(int i=0;i<magazine.size();i++)
        {
            char c = magazine[i];
            if(mp.find(c) !=mp.end())
            {
                mp[c]--;
                if(mp[c]==0)
                    mp.erase(c);
            }
        }
        if(mp.empty())
            return true;
        return false;
    }
};