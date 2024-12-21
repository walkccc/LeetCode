class Solution:
  def minimumOperationsToMakeEqual(self, x, y):
    if x <= y:
      return y - x

    queue = collections.deque([x])
    seen = set()

    ans = 0
    while queue:
      for _ in range(len(queue)):
        num = queue.popleft()
        if num == y:
          return ans
        if num in seen:
          continue
        seen.add(num)
        if num % 11 == 0:
          queue.append(num // 11)
        if num % 5 == 0:
          queue.append(num // 5)
        queue.append(num - 1)
        queue.append(num + 1)
      ans += 1
