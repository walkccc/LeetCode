class Solution:
  def minimumPushes(self, word: str) -> int:
    freqs = sorted(collections.Counter(word).values(), reverse=True)
    return sum(freq * (i // 8 + 1) for i, freq in enumerate(freqs))
