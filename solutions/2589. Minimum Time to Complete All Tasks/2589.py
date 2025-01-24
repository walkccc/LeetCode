class Solution:
  def findMinimumTime(self, tasks: list[list[int]]) -> int:
    kMax = 2000
    running = [False] * (kMax + 1)

    # Sort tasks by end.
    for start, end, duration in sorted(tasks, key=lambda x: x[1]):
      neededDuration = (duration -
                        sum(running[i] for i in range(start, end + 1)))
      # Greedily run the task as late as possible so that later tasks can run
      # simultaneously.
      i = end
      while neededDuration > 0:
        if not running[i]:
          running[i] = True
          neededDuration -= 1
        i -= 1

    return sum(running)
