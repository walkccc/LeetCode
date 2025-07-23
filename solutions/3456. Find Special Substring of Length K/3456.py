class Solution:
  def hasSpecialSubstring(self, s: str, k: int) -> bool:
    return any(len(list(group)) == k for _, group in groupby(s))
