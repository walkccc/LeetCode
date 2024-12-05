class Solution:
  def numKLenSubstrNoRepeats(self, s: str, k: int) -> int:
    ans = 0
    unique = 0
    count = collections.Counter()

    for i, c in enumerate(s):
      count[c] += 1
      if count[c] == 1:
        unique += 1
      if i >= k:
        count[s[i - k]] -= 1
        if count[s[i - k]] == 0:
          unique -= 1
        if unique == k:
          ans += 1

    return ans
