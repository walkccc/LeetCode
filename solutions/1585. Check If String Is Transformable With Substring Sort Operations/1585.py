class Solution:
  def isTransformable(self, s: str, t: str) -> bool:
    if collections.Counter(s) != collections.Counter(t):
      return False

    positions = [collections.deque() for _ in range(10)]

    for i, c in enumerate(s):
      positions[int(c)].append(i)

    # For each digit in `t`, check if we can put this digit in `s` at the same
    # position as `t`. Ensure that all the left digits are equal to or greater
    # than it. This is because the only operation we can perform is sorting in
    # ascending order. If there is a digit to the left that is smaller than it,
    # we can never move it to the same position as in `t`. However, if all the
    # digits to its left are equal to or greater than it, we can move it one
    # position to the left until it reaches the same position as in `t`.
    for c in t:
      d = int(c)
      front = positions[d].popleft()
      for smaller in range(d):
        if positions[smaller] and positions[smaller][0] < front:
          return False

    return True
