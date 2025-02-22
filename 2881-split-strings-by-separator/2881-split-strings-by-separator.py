class Solution:
    def splitWordsBySeparator(self, words: List[str], separator: str) -> List[str]:
        res = []
        for item in words:
            temp = item.split(separator)
            temp = filter(lambda x: len(x) != 0, temp)
            res.extend(temp)
        
        return res