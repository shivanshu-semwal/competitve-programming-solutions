class Solution:
    
    def __init__(self):
        self.state = {}
        self.items = {}

    def getMaxChainAtI(self, i, j):
        if i + 1 not in self.items:
            return 1

        if i in self.state:
            if j in self.state[i]:
                return self.state[i][j]
        else:
            self.state[i] = {}

        ans = 0
        for k in range(0, len(self.items[i+1])):
            if self.isPredecessor(self.items[i][j], self.items[i+1][k]):
                ans = max(ans, self.getMaxChainAtI(i+1, k))
        
        self.state[i][j] = ans + 1
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

        for word in words:
            key = len(word)
            if key in self.items:
                self.items[key].append(word)
            else:
                self.items[key] = [word]

        for i in self.items.keys():
            t = len(self.items[i])
            for j in range(0, t):
                ans = max(ans , self.getMaxChainAtI(i, j))
                print()

        return ans