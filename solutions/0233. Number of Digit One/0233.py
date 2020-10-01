class Solution:
    def countDigitOne(self, n: int) -> int:
        if n < 0:
            return 0

        ans = 0
        i = 1
        num = n

        while i <= n:
            prefix = n // (i * 10)
            suffix = n % i
            currentDigit = num % 10
            ans += prefix * i
            if currentDigit > 1:
                ans += i
            elif currentDigit == 1:
                ans += suffix + 1
            i *= 10
            num //= 10

        return ans
