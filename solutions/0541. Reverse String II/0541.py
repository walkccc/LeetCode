class Solution:
  def reverseStr(self, s: str, k: int) -> str:
    return s[:k][::-1] + s[k:2 * k] + self.reverseStr(s[2 * k:], k) if s else ""
