class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> arr;
        for (int i = 1; i <= n; i++) {
            arr.push_back(i);
        }

        int i = 0;
        while (arr.size() > 1) {
            int idxToDelete = (i + k - 1) % arr.size();

            arr.erase(arr.begin() + idxToDelete);

            i = idxToDelete;
        }
        return arr[0];
    }
};