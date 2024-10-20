class Solution:
  def taskSchedulerII(self, tasks: list[int], space: int) -> int:
    taskToNextAvailable = collections.defaultdict(int)
    ans = 0

    for task in tasks:
      ans = max(ans + 1, taskToNextAvailable[task])
      taskToNextAvailable[task] = ans + space + 1

    return ans
