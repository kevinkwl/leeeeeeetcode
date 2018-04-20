class Solution:
    def mostCommonWord(self, paragraph, banned):
        """
        :type paragraph: str
        :type banned: List[str]
        :rtype: str
        """
        words = paragraph.strip().split()
        freq = {}
        for  word in words:
            w = word.strip("!?',;.").lower()
            if w not in freq:
                freq[w] = 1
            else:
                freq[w] += 1
        for ban in banned:
            freq.pop(ban, None)
        
        return sorted(freq.items(), key=lambda x: x[1], reverse=True)[0][0]
