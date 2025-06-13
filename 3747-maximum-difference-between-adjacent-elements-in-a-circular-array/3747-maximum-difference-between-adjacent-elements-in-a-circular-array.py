class Solution:
    def maxAdjacentDistance(self, nums: List[int]) -> int:
        n = len(nums)
        maxDiff = -1
        for i in range(1,n):
            diff = abs(nums[i-1] - nums[i])
            maxDiff = max(diff, maxDiff)
        
        diff = abs(nums[0] - nums[n-1])
        maxDiff = max(diff, maxDiff)
        return maxDiff