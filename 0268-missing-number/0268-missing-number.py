class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        ans = 0

        for i in range(1, n+1):
            ans ^= i
        
        for item in nums:
            ans ^= item
        return ans


        # [3,0,1]
        # first loop , ans = 0^1^2^3
        # second loop, ans = 0^1^2^3 ^ elements of nums
        #              ans = 0^1^2^3 ^ 3^0^1
        #              ans = 2