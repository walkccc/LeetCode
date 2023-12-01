class Solution:
  def canConstruct(self, s: str, k: int) -> bool:
    # If |s| < k, we cannot construct k strings from the s.
    # If the number of letters that have odd counts > k, the minimum number of
    # palindromic strings we can construct is > k.
    return sum(freq & 1
               for freq in collections.Counter(s).values()) <= k <= len(s)
