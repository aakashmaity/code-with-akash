class Solution:
    def climbStairs(self, n: int) -> int:
        memo = {}
        return self.solve(n, memo)

    def solve(self, n: int, memo: dict[int,int]) -> int:
        if n <= 1:
            return 1

        if n not in memo:
            memo[n] = self.solve(n-1, memo) + self.solve(n-2, memo)

        return memo[n]
        