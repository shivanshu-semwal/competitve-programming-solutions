class Solution:
    
    def __init__(self):
        self.state = {}

    def getMaxChainAtI(self, i, words):
        if i + 1 == len(words):
            return 1
        if i in self.state:
            return self.state[i]
        ans = 0
        for j in range(i+1, len(words)):
            if len(words[i]) + 1 < len(words[j]):
                break
            if self.isPredecessor(words[i], words[j]):
                ans = max(ans, self.getMaxChainAtI(j, words))
        
        self.state[i] = ans + 1
        return ans + 1

    def isPredecessor(self, s1, s2):
        if len(s1) + 1 != len(s2):
            return False
        count, i, j = 0, 0, 0
        while i < len(s1) and j < len(s2):
            if s1[i] != s2[j]:
                count += 1
                j += 1
            else:
                j += 1
                i += 1
        return False if count >= 2 else True

    def longestStrChain(self, words: List[str]) -> int:
        """
        return length of longest word chain
        """
        ans = 0
        words = sorted(words, key=lambda word: len(word))
        for i in range(0, len(words)):
            ans = max(ans, self.getMaxChainAtI(i, words))
        return ans