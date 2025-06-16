class Solution:
    def maximumDifference(self, nums: List[int]) -> int:
        mini = 10**100
        ans = -1

        for a in nums:
            if a < mini:
                mini = a
            ans = max(a - mini, ans)

        if ans == 0:
            return -1
        return ans

