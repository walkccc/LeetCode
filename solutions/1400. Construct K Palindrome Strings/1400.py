class Solution:
  def canConstruct(self, s: str, k: int) -> bool:
    # If the len(s) < k, we cannot construct k strings from s.
    # If the # of characters that have odd counts is > k, the min # of
    # palindrome strings we can construct is > k.
    return sum(freq & 1 for freq in collections.Counter(s).values()) <= k <= len(s)
