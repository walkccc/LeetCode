class Solution:
  def maxCount(self, banned: list[int], n: int, maxSum: int) -> int:
    ans = 0
    summ = 0
    bannedSet = set(banned)

    for i in range(1, n + 1):
      if i not in bannedSet and summ + i <= maxSum:
        ans += 1
        summ += i

    return ans
