class Solution:
    def splitWordsBySeparator(self, words: List[str], separator: str) -> List[str]:
        ans = []

        for word in words:
            for str in word.split(separator):
                if str:
                    ans.append(str)
            
        return ans