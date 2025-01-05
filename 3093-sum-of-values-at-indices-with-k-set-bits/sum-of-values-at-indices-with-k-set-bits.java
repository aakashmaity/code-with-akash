class Solution {
    public int sumIndicesWithKSetBits(List<Integer> nums, int k) {
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            int cnt=0;
            int idx = i;
            while(idx > 0){
                cnt += idx & 1;
                idx = idx >> 1;
            }
            if(cnt == k)
                sum += nums.get(i);
        }
        return sum;
    }
}