class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        freq = defaultdict(int)
        banned_set = set(banned)
        word = ""

        for char in paragraph:
            if char.isalnum():
                word += char.lower()
            else:
                if word and word not in banned_set:
                    freq[word] += 1
                word=""
        
        if word and word not in banned_set:
            freq[word] += 1

        
        maxCount = 0
        res = ""

        for word,count in freq.items():
            if count > maxCount:
                maxCount = count
                res = word
        
        return res