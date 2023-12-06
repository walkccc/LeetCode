class Solution:
  def shareCandies(self, candies: List[int], k: int) -> int:
    ans = 0
    count = collections.Counter(candies)
    unique = len(count)

    for i, candy in enumerate(candies):
      count[candy] -= 1
      if count[candy] == 0:
        del count[candy]
        unique -= 1
      if i >= k:
        count[candies[i - k]] += 1
        if count[candies[i - k]] == 1:
          unique += 1
      if i >= k - 1:
        ans = max(ans, unique)

    return ans
