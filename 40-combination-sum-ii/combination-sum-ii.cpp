class Solution {
public:
    int n,T;
    vector<vector<int>> ans;
    void backtracking(vector<int>& candidates,vector<int>& temp,int idx, int target){
        if(target < 0){
            return;
        }
        if(target == 0){
            ans.push_back(temp);
            return;
        }


        for(int i = idx; i<n;i++){
            if(i > idx && candidates[i] == candidates[i-1]){
                continue;
            }

            int num = candidates[i];
            temp.push_back(num);  // add-Do
            backtracking(candidates, temp,i+1,target - num);  // Explore
            temp.pop_back();   //undo
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n = candidates.size();
        vector<int> temp;

        sort(begin(candidates),end(candidates));

        backtracking(candidates,temp,0,target);
        return ans;
    }
};