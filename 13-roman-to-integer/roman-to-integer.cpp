class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };

        int ans=0;
        int decr=0;
        for(int i=0;i<s.size();i++)
        {
            ans+=mp[s[i]];
            if(s[i]=='V' || s[i]=='X')
            {
                if(i>0 && s[i-1] == 'I')
                {
                    decr+=(1+1);
                }
            }
            else if(s[i]=='L' || s[i]=='C')
            {
                if(i>0 && s[i-1] == 'X')
                {
                    decr+=(10+10);
                }
            }
            else if(s[i]=='D' || s[i]=='M')
            {
                if(i>0 && s[i-1] == 'C')
                {
                    decr+=(100+100);
                }
            }    
        }
        return ans-decr;

    } 
};