class Solution:
  def isTransformable(self, s: str, t: str) -> bool:
    if collections.Counter(s) != collections.Counter(t):
      return False

    positions = [collections.deque() for _ in range(10)]

    for i, c in enumerate(s):
      positions[int(c)].append(i)

    for c in t:
      d = int(c)
      front = positions[d].popleft()
      for smaller in range(d):
        if positions[smaller] and positions[smaller][0] < front:
          return False

    return True
