class Solution:
  def maxDistToClosest(self, seats: list[int]) -> int:
    n = len(seats)
    ans = 0
    j = -1

    for i in range(n):
      if seats[i] == 1:
        ans = i if j == -1 else max(ans, (i - j) // 2)
        j = i

    return max(ans, n - j - 1)
