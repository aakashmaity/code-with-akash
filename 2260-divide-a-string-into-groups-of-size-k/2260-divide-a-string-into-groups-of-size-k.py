class Solution:
    def divideString(self, s: str, k: int, fill: str) -> List[str]:
        rem = len(s) % k
    
        res = [s[i:i+k].ljust(k, fill) for i in range(0, len(s), k)]
        return res
        