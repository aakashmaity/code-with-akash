class Solution:
    def minMaxDifference(self, num: int) -> int:
        s = str(num)

        max_val = s
        for ch in s:
            if ch != '9':
                max_val = s.replace(ch, '9')  # Replace each occurrence of 'ch' with '9'
                break

        min_val = s
        for ch in s:
            if ch != '0':
                min_val = s.replace(ch, '0')
                break
        
        return int(max_val) - int(min_val)

        