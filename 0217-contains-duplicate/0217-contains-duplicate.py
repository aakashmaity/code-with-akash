class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        from collections import defaultdict
        d = defaultdict(int)
        for item in nums:
            if d[item] >= 1:
                return True
            d[item] += 1
            
        return False