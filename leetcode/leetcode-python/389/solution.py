class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        s_dic = Counter(s)
        t_dic = Counter(t)
        for char in t_dic:
            if not s_dic[char] == t_dic[char]:
                return char
        