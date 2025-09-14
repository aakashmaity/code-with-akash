class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string>v;

        //extracting words from string 's'
        string str;
        stringstream ss(s);
        while(getline(ss,str,' '))
        {
            v.push_back(str);
        }
        
        if(v.size() != pattern.size())
            return false;


        unordered_map<char,string>mp;
        for(int i=0;i<pattern.size();i++)
        {
            char c = pattern[i];
            if(mp.find(c) != mp.end())
            {
                if(mp[c] != v[i])
                    return false;
            }
            else
            {
                for(auto it :mp)
                {
                    if(it.second == v[i])
                        return false;
                }
                mp[c]=v[i];
            }
                
        }
        return true;

    }
};