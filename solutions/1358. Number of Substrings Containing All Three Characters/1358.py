class Solution:
  # Similar to 3. Longest SubWithout Repeating Characters
  def numberOfSubstrings(self, s: str) -> int:
    ans = 0
    count = {c: 0 for c in 'abc'}

    l = 0
    for c in s:
      count[c] += 1
      while min(count.values()) > 0:
        count[s[l]] -= 1
        l += 1
      # s[0..r], s[1..r], ..., s[l - 1..r] are satified strings.
      ans += l

    return ans
