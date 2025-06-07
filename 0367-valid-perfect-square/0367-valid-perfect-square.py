class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        return self.isPerfectSquare(num)
    
    def isPerfectSquare(self, num: int) -> bool:
        s, e = 1, num

        while(s<=e):
            mid = s + (e-s)//2
            if(mid * mid == num):
                return True
            elif( mid * mid > num):
                e = mid - 1
            else:
                s = mid + 1
        
        return False