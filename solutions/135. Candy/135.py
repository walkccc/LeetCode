class Solution:
  def candy(self, ratings: list[int]) -> int:
    n = len(ratings)

    ans = 0
    l = [1] * n
    r = [1] * n

    for i in range(1, n):
      if ratings[i] > ratings[i - 1]:
        l[i] = l[i - 1] + 1

    for i in range(n - 2, -1, -1):
      if ratings[i] > ratings[i + 1]:
        r[i] = r[i + 1] + 1

    for a, b in zip(l, r):
      ans += max(a, b)

    return ans
