class Solution:
  def minimumOperations(self, nums: list[int], start: int, goal: int) -> int:
    q = collections.deque([start])
    seen = {start}

    step = 1
    while q:
      for _ in range(len(q)):
        x = q.popleft()
        for num in nums:
          for res in (x + num, x - num, x ^ num):
            if res == goal:
              return step
            if res < 0 or res > 1000 or res in seen:
              continue
            seen.add(res)
            q.append(res)
      step += 1

    return -1
