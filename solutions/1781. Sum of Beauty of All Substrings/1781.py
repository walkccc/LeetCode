class Solution:
  def beautySum(self, s: str) -> int:
    ans = 0

    for i in range(len(s)):
      count = collections.Counter()
      for j in range(i, len(s)):
        count[s[j]] += 1
        ans += max(count.values()) - min(count.values())

    return ans
