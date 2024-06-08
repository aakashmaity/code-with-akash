class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string>s(dictionary.begin(), dictionary.end());
        int found = 0;
        string ans = "";
        string temp="";
        for(char c:sentence)
        {
            if(found==1 && c!=' ')
               continue;
            else if(found==1 && c==' ')
               {
                  ans=ans+" ";
                  found=0;
                  temp="";
                  continue;
               }
            else if(found==0 && c==' ')
                {
                    ans=ans+temp+" ";
                    temp="";
                    continue;
                }
            temp+=c;
            if(s.find(temp)!=s.end())
            {
                found=1;
                ans+=temp;
                temp="";
            }
        }
        if(temp!=" ")
           ans+=temp;
        return ans;
    }
};

/*
cat bat rat
cattle was rattled by the battery
cat
  |
  found here in the set
*/