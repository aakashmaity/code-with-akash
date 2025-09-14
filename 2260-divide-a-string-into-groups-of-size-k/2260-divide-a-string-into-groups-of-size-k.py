class Solution:
    def divideString(self, s: str, k: int, fill: str) -> List[str]:
        rem = len(s) % k
        if rem != 0:
            s = s + fill * (k - rem)  # added extra 'fill' element to string
        
        res = [s[i:i+k] for i in range(0, len(s), k)]
        return res
        