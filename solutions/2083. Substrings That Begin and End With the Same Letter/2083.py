class Solution:
  def numberOfSubstrings(self, s: str) -> int:
    ans = 0
    count = collections.Counter()

    for c in s:
      ans += count[c] + 1
      count[c] += 1

    return ans
