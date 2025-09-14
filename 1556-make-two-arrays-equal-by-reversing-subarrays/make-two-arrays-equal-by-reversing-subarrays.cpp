class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        if(arr.size() != target.size()){
            return false;
        }
        vector<int> freq(1001,0);

        for(int i=0;i<arr.size();i++){
            freq[arr[i]]++;
        }

        for(int i=0;i<target.size();i++){
            if(freq[target[i]] <=0 ){
                return false;
            }
            freq[target[i]]--;
        }

        return true;
    }
};