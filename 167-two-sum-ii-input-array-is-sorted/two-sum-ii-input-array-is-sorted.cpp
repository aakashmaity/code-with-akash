class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int start = 0;
        int end = n-1;

        while(start<end){
            int a=numbers[start];
            int b=numbers[end];
            if(a+b == target){
                return {start+1,end+1};
            }
            else if(a+b < target){
                start++;
            }
            else{
                end--;
            }
        }
        return {};
    }
};