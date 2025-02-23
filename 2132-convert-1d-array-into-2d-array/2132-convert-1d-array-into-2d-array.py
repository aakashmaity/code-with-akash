class Solution:
    def construct2DArray(self, original: List[int], m: int, n: int) -> List[List[int]]:
        if n*m != len(original):
            return []
            
        row=0
        col=0
        res = []
        temp = []
        for item in original:
            if col == n-1:
                temp.append(item)
                res.append(temp)
                print(temp)
                row += 1
                col = 0
                temp = []
            else:
                temp.append(item)
                col += 1
        
        return res  

