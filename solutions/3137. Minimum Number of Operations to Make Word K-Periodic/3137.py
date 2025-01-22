class Solution:
  def minimumOperationsToMakeKPeriodic(self, word: str, k: int) -> int:
    count = collections.Counter(word[i:i + k] for i in range(0, len(word), k))
    return len(word) // k - max(count.values())
