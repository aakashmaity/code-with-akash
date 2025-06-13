class Solution:
    def maxAdjacentDistance(self, nums: List[int]) -> int:
        n = len(nums)
        maxDiff = -1
        for i in range(n):
            diff = abs(nums[i] - nums[(i+1) % n])
            maxDiff = max(diff, maxDiff)
        return maxDiff