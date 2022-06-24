class Solution:
  def leastInterval(self, tasks: List[str], n: int) -> int:
    count = Counter(tasks)
    maxFreq = max(count.values())
    # put the most frequent task in the slot first
    maxFreqTaskOccupy = (maxFreq - 1) * (n + 1)
    # get # of tasks with same frequency as maxFreq,
    # we'll append them after maxFreqTaskOccupy
    nMaxFreq = sum(value == maxFreq for value in count.values())
    # max(
    #   the most frequent task is frequent enough to force some idle slots,
    #   the most frequent task is not frequent enough to force idle slots
    # )
    return max(maxFreqTaskOccupy + nMaxFreq, len(tasks))
