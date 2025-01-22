class Solution:
  def minimumRounds(self, tasks: list[int]) -> int:
    freqs = collections.Counter(tasks).values()
    return -1 if 1 in freqs else sum((f + 2) // 3 for f in freqs)
