class Solution:
  def minimumDeletions(self, word: str, k: int) -> int:
    ans = math.inf
    count = collections.Counter(word)

    for minFreq in count.values():
      deletions = 0
      for freq in count.values():
        if freq < minFreq:
          deletions += freq
        else:
          deletions += max(0, freq - (minFreq + k))
      ans = min(ans, deletions)

    return ans
