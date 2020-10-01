class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False

        ans = 0
        y = x

        while y:
            ans = ans * 10 + y % 10
            y //= 10

        return ans == x
