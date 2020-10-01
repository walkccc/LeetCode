class Solution:
    def generateParenthesis(self, n):
        ans = []

        self.helper('', n, n, ans)

        return ans

    def helper(self, str, l, r, ans):
        if l == 0 and r == 0:
            ans.append(str)
        if l > 0:
            self.helper(str + '(', l - 1, r, ans)
        if l < r:
            self.helper(str + ')', l, r - 1, ans)
