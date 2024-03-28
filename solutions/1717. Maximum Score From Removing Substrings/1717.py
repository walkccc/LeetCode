class Solution:
  def maximumGain(self, s: str, x: int, y: int) -> int:
    # The assumption that gain('ab') > gain('ba') while removing 'ba' first is
    # optimal is contradicted. Only 'b(ab)a' satisfies the condition of
    # preventing two 'ba' removals, but after removing 'ab', we can still
    # remove one 'ba', resulting in a higher gain. Thus, removing 'ba' first is
    # not optimal.
    return self._gain(s, 'ab', x, 'ba', y) if x > y \
        else self._gain(s, 'ba', y, 'ab', x)

  # Returns the points gained by first removing sub1 ('ab' | 'ba') from s with
  # point1, then removing sub2 ('ab' | 'ba') from s with point2.
  def _gain(self, s: str, sub1: str, point1: int, sub2: str, point2: int) -> int:
    points = 0
    stack1 = []
    stack2 = []

    # Remove 'sub1' from s with point1 gain.
    for c in s:
      if stack1 and stack1[-1] == sub1[0] and c == sub1[1]:
        stack1.pop()
        points += point1
      else:
        stack1.append(c)

    # Remove 'sub2' from s with point2 gain.
    for c in stack1:
      if stack2 and stack2[-1] == sub2[0] and c == sub2[1]:
        stack2.pop()
        points += point2
      else:
        stack2.append(c)

    return points
