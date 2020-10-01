class Solution:
    def longestValidParentheses(self, s: str) -> int:
        ans = 0
        l = 0
        r = 0

        for i in range(len(s)):
            if s[i] == '(':
                l += 1
            else:
                r += 1
            if l == r:
                ans = max(ans, 2 * r)
            elif r > l:
                l = 0
                r = 0

        l = 0
        r = 0

        for i in range(len(s) - 1, -1, -1):
            if s[i] == '(':
                l += 1
            else:
                r += 1
            if l == r:
                ans = max(ans, 2 * l)
            elif l > r:
                l = 0
                r = 0

        return ans
