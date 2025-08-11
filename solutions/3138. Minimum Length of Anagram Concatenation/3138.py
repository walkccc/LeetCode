class Solution:
  def minAnagramLength(self, s: str) -> int:
    n = len(s)
    for k in range(1, n + 1):
      if n % k == 0 and self._canFormAnagram(s, k):
        return k
    return n

  def _canFormAnagram(self, s: str, k: int) -> bool:
    """Returns True if we can concatenate an anagram of length k to s."""
    anagramCount = collections.Counter(s[:k])
    return all(collections.Counter(s[i:i + k]) == anagramCount
               for i in range(k, len(s), k))
