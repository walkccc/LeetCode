class Solution:
  def minimumChairs(self, s: str) -> int:
    ans = 0
    chairs = 0

    for c in s:
      chairs += 1 if c == 'E' else -1
      ans = max(ans, chairs)

    return ans
