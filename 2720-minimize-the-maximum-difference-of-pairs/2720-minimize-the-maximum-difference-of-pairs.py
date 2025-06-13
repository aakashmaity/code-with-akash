class Solution:
    def minimizeMax(self, nums: List[int], p: int) -> int:
        n = len(nums)   
        if n == 0 or n == 1:
            return 0

        nums.sort()

        low = 0
        high = nums[n-1] - nums[0]
        while low <= high :
            mid = low + (high-low)//2
            if(self.solve(nums, n, p, mid)):
                high = mid - 1
            else:
                low = mid + 1
        return low

    def solve(self, nums, n, p, mid) -> bool:
        count = 0
        
        i = 1
        while i < n:
            if nums[i] - nums[i-1] <= mid:
                count += 1
                i += 1
            if(count >= p):
                return True
            i += 1
        return False
        