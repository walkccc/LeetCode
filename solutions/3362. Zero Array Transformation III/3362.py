from sortedcontainers import SortedList


class Solution:
  def maxRemoval(self, nums: list[int], queries: list[list[int]]) -> int:
    q = collections.deque(sorted(queries))
    available = SortedList()  # available `r`s
    running = SortedList()  # running `r`s

    for i, num in enumerate(nums):
      while q and q[0][0] <= i:
        available.add(q.popleft()[1])
      while running and running[0] < i:
        running.pop(0)
      while num > len(running):
        if not available or available[-1] < i:
          return -1
        running.add(available.pop())

    return len(available)
