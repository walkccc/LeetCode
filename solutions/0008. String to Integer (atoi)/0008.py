class Solution:
    def myAtoi(self, str: str) -> int:
        ans = 0
        str = str.strip()

        if not str:
            return 0

        sign = -1 if str[0] == '-' else 1
        if str[0] in {'-', '+'}:
            str = str[1:]

        for c in str:
            if not c.isdigit():
                break
            ans = ans * 10 + ord(c) - ord('0')

        return max(-2**31, min(2**31 - 1, sign * ans))
