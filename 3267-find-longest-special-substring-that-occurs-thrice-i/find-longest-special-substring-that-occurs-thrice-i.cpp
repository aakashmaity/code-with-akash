class Solution {
public:

    bool Is_Valid(string& str, int target){

        int count = 0;
        vector<int> seen(26, 0);

        char last_valid = '.';
        for(int i = 0; i < str.size(); i++){

            if(str[i] == last_valid){
                count++;
            }else{
                count = 1;
                last_valid = str[i];
            }

            if(count >= target && ++seen[str[i]-'a'] == 3){
                return true;
            }
        }

        return false;
    }

    int maximumLength(string s) {

        int low = 0;
        int high = s.size()-1;

        while(low < high){

            int mid = (low + high)/2;

            if(Is_Valid(s, mid)){
                low = mid+1;
            }else{
                high = mid;
            }
        }

        return low-1;
    }
};