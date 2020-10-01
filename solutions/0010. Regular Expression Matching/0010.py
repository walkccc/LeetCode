class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        if not p:
            return not s

        firstMatch = bool(s) and p[0] in {s[0], '.'}

        if len(p) >= 2 and p[1] == '*':
            return (self.isMatch(s, p[2:]) or firstMatch and self.isMatch(s[1:], p))
        return firstMatch and self.isMatch(s[1:], p[1:])
