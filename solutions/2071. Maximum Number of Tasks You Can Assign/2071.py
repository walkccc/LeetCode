from sortedcontainers import SortedList


class Solution:
  def maxTaskAssign(
      self,
      tasks: list[int],
      workers: list[int],
      pills: int,
      strength: int,
  ) -> int:
    tasks.sort()
    workers.sort()

    def canComplete(k: int, pillsLeft: int) -> bool:
      """Returns True if we can finish k tasks."""
      # k strongest workers
      sortedWorkers = SortedList(workers[-k:])

      # Out of the k smallest tasks, start from the biggest one.
      for i in reversed(range(k)):
        # Find the first worker that has strength >= tasks[i].
        index = sortedWorkers.bisect_left(tasks[i])
        if index < len(sortedWorkers):
          sortedWorkers.pop(index)
        elif pillsLeft > 0:
          # Find the first worker that has strength >= tasks[i] - strength.
          index = sortedWorkers.bisect_left(tasks[i] - strength)
          if index < len(sortedWorkers):
            sortedWorkers.pop(index)
            pillsLeft -= 1
          else:
            return False
        else:
          return False

      return True

    ans = 0
    l = 0
    r = min(len(tasks), len(workers))

    while l <= r:
      m = (l + r) // 2
      if canComplete(m, pills):
        ans = m
        l = m + 1
      else:
        r = m - 1

    return ans
