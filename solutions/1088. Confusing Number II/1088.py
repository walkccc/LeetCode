class Solution:
  def confusingNumberII(self, n: int) -> int:
    digitToRotated = [(0, 0), (1, 1), (6, 9), (8, 8), (9, 6)]

    def dfs(num: int, rotatedNum: int, unit: int) -> int:
      ans = 0 if num == rotatedNum else 1
      # Add one more digit
      for digit, rotated in digitToRotated:
        if digit == 0 and num == 0:
          continue
        nextNum = num * 10 + digit
        if nextNum > n:
          break
        ans += dfs(nextNum, rotated * unit + rotatedNum, unit * 10)
      return ans

    return dfs(0, 0, 1)
