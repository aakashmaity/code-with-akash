class Solution {
    public int[] maxSubsequence(int[] nums, int k) {
        int n = nums.length;
        int[][] valueWithIndex = new int[n][2];

        for(int i=0;i<n;i++){
            valueWithIndex[i] = new int[]{nums[i], i};
        }

// This compares values (a[0] and b[0]) and sorts bigger values first
        Arrays.sort(valueWithIndex, (a,b) -> b[0] - a[0]);
// This sorts only the first k elements by their original indices (a[1]) rest is unchanged
        Arrays.sort(valueWithIndex, 0, k, (a, b) -> a[1] - b[1]);

        int[] res = new int[k];
        for(int i=0;i<k;i++){
            res[i] = valueWithIndex[i][0];
        }
        return res;
        
    }
}