class Solution:
  def minimumOperations(self, nums: list[int], start: int, goal: int) -> int:
    ans = 0
    q = collections.deque([start])
    seen = {start}

    while q:
      ans += 1
      for _ in range(len(q)):
        x = q.popleft()
        for num in nums:
          for res in (x + num, x - num, x ^ num):
            if res == goal:
              return ans
            if res < 0 or res > 1000 or res in seen:
              continue
            seen.add(res)
            q.append(res)

    return -1
