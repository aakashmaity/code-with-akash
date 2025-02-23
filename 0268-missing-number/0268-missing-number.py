class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        n = len(nums)
        arr = sorted(nums)
        
        if arr[0] != 0:
            return 0

        for i in range(1,n):
            if arr[i-1]+1 != arr[i]:
                return arr[i-1]+1
            
        return n