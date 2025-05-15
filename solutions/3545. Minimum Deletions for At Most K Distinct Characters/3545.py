class Solution:
  def minDeletion(self, s: str, k: int) -> int:
    count = collections.Counter(s)
    if len(count) <= k:
      return 0
    freqs = sorted(count.values())
    return sum(freqs[:len(freqs) - k])
