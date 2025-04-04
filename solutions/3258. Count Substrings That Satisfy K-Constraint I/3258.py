class Solution:
  def countKConstraintSubstrings(self, s: str, k: int) -> int:
    ans = 0
    count = [0, 0]

    l = 0
    for r, c in enumerate(s):
      count[int(c)] += 1
      while min(count) > k:
        count[int(s[l])] -= 1
        l += 1
      ans += r - l + 1

    return ans
