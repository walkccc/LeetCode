class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) == 0:
            return ""
        if len(strs) == 1:
            return strs[0]

        ans = ""
        mini = len(strs[0])
        isMatch = True

        for i in range(1, len(strs)):
            mini = min(mini, len(strs[i]))

        for i in range(mini):
            c = strs[0][i]
            for j in range(1, len(strs)):
                if c != strs[j][i]:
                    isMatch = False
                    break
            if not isMatch:
                break
            ans += c

        return ans
