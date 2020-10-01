class Solution:
    def numDecodings(self, s: str) -> int:
        if not s or s[0] == '0':
            return 0
        if len(s) == 1:
            return 1

        dp1 = 1
        dp2 = 1

        for i in range(1, len(s)):
            dp = 0
            if not self.isValid(s[i]) and not self.isValid(s[i - 1], s[i]):
                return 0
            if self.isValid(s[i]):
                dp += dp1
            if self.isValid(s[i - 1], s[i]):
                dp += dp2
            dp2 = dp1
            dp1 = dp

        return dp1

    def isValid(self, a: chr, b=None) -> bool:
        if b:
            return a == '1' or (a == '2' and b <= '6')
        return a != '0'
