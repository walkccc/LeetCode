class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        l = 1
        r = num + 1

        while l < r:
            m = (l + r) // 2
            if m > num / m:
                r = m
            else:
                l = m + 1

        return (l - 1) * (l - 1) == num
