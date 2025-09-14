class Solution:
    def maxDifference(self, s: str) -> int:
        from collections import Counter

        freq = Counter(s)
        odd = 0
        even = len(s)
        for cnt in freq.values():
            if cnt % 2 == 1:
                odd = max(odd, cnt)
            elif cnt != 0:
                even = min(even, cnt)
        return odd - even