class Solution:
  def leastInterval(self, tasks: List[str], n: int) -> int:
    count = Counter(tasks)

    maxFreq = max(count.values())
    ans = (maxFreq - 1) * (n + 1)
    ans += sum(map(lambda value: value == maxFreq, count.values()))

    return max(ans, len(tasks))
