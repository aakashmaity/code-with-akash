class Solution:
    def maximumDifference(self, nums: List[int]) -> int:
        mini = 10**9
        ans = -1

        for a in nums:
            if a <= mini:
                mini = a
            else:
                ans = max(a - mini, ans)

        return ans

