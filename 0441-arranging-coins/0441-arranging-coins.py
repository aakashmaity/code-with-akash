class Solution:
    def arrangeCoins(self, n: int) -> int:
        s, e = 0, n
        mid = 0
        while(s<=e):
            mid = s+(e-s)//2
            totalCoins = mid*(mid+1)//2
            if(totalCoins == n):
                return mid
            elif(totalCoins > n):
                e = mid - 1
            else:
                s = mid + 1
        return e
        
            
        