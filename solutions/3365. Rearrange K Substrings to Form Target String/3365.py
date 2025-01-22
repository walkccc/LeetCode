class Solution:
  def isPossibleToRearrange(self, s: str, t: str, k: int) -> bool:
    n = len(s)
    return (collections.Counter(s[i:i + n // k] for i in range(0, n, n // k)) ==
            collections.Counter(t[i:i + n // k] for i in range(0, n, n // k)))
