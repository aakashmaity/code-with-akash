class Solution:
    def findKDistantIndices(self, nums: List[int], key: int, k: int) -> List[int]:
        n = len(nums)
        keyIndex = []

        for i in range(n):
            if nums[i] == key:
                keyIndex.append(i)
        
        res = []
        for i in range(n):
            for j in keyIndex:
                if abs(i-j) <= k:
                    res.append(i)
                    break
        return res


        