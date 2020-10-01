class Solution:
    def binaryGap(self, N: int) -> int:
        ans = 0
        prevOneIndex = 30
        i = 0
        n = N

        while n > 0:
            if n % 2 == 1:
                ans = max(ans, i - prevOneIndex)
                prevOneIndex = i
            n >>= 1
            i += 1

        return ans
