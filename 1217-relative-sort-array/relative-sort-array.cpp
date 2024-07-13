class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> mp;

        // store the order of sorting using index.
        // 2->0, 1->1, 4->2, 3->3, 9->4, 6->5
        for(int i=0;i<arr2.size();i++){
            mp[arr2[i]] = i;
        }

        // 7->1e9, 19->1e9
        for(int num : arr1){
            if(!mp.count(num)){
                mp[num] = 1e9;
            }
        }
        
        // using '&' (in [&]) we can acces outer veriable
        auto lambda = [&](int &num1, int &num2){
            if(mp[num1] == mp[num2]){  // num1->ie9, num2->1e9
                return num1 < num2;
            }
            return mp[num1] < mp[num2];
        };

        sort(begin(arr1),end(arr1),lambda);
        return arr1;
    }
};