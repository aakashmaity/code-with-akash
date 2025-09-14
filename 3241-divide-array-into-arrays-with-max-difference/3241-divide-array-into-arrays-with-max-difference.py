class Solution:
    def divideArray(self, nums: List[int], k: int) -> List[List[int]]:
        nums.sort()
        res = []
        temp = []
        i = 0
        while i < len(nums): 
            temp.append(nums[i])
            i+=1
            if i % 3 == 0:
                res.append(temp)
                if temp[2] - temp[0] > k:
                    return []
                temp = []
        return res
        

        