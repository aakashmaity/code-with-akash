class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        n = len(nums)
        st = set(nums)
        res = []
        for i in range(1,n+1):
            if i not in st:
                res.append(i)

        return res
