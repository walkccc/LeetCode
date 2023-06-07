class Solution:
  def leastInterval(self, tasks: List[str], n: int) -> int:
    count = collections.Counter(tasks)
    maxFreq = max(count.values())
    # Put the most frequent task in the slot first
    maxFreqTaskOccupy = (maxFreq - 1) * (n + 1)
    # Get # Of tasks with same frequency as maxFreq,
    # we'll append them after maxFreqTaskOccupy
    nMaxFreq = sum(value == maxFreq for value in count.values())
    # Max(
    #   the most frequent task is frequent enough to force some idle slots,
    #   the most frequent task is not frequent enough to force idle slots
    # )
    return max(maxFreqTaskOccupy + nMaxFreq, len(tasks))
