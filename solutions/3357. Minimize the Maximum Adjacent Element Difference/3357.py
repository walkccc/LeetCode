class Solution:
  def minDifference(self, nums: list[int]) -> int:
    maxPositiveGap = 0
    mn = 1_000_000_000
    mx = 0

    for a, b in itertools.pairwise(nums):
      if (a == -1) != (b == -1):
        positive = max(a, b)
        mn = min(mn, positive)
        mx = max(mx, positive)
      else:
        maxPositiveGap = max(maxPositiveGap, abs(a - b))

    l = maxPositiveGap
    r = (mx - mn + 1) // 2
    return bisect.bisect_left(
        range(l, r), True,
        key=lambda m: self._check(nums, m, mn + m, mx - m)) + l

  def _check(self, nums: list[int], m: int, x: int, y: int) -> bool:
    """
    Returns True if it's possible have `m` as maximum absolute difference
    between adjacent numbers, where -1s are replaced with `x` or `y`.
    """
    gapLength = 0
    prev = 0

    for num in nums:
      if num == -1:
        gapLength += 1
        continue
      if prev > 0 and gapLength > 0:
        if gapLength == 1 and not self._checkSingleGap(prev, num, m, x, y):
          return False
        if gapLength > 1 and not self._checkMultipleGaps(prev, num, m, x, y):
          return False
      prev = num
      gapLength = 0

    # Check leading gaps
    if nums[0] == -1:
      num = next((num for num in nums if num != -1), -1)
      if num != -1 and not self._checkBoundaryGaps(num, m, x, y):
        return False

    # Check trailing gaps
    if nums[-1] == -1:
      num = next((num for num in reversed(nums) if num != -1), -1)
      if num != -1 and not self._checkBoundaryGaps(num, m, x, y):
        return False

    return True

  def _checkSingleGap(self, a: int, b: int, m: int, x: int, y: int) -> bool:
    """
    Returns true if it's possible to have at most `m` as the minimized maximum
    difference for a sequence with a single -1 between two numbers.
    e.g. [a, -1, b] can be filled with either x or y.
    """
    gapWithX = max(abs(a - x), abs(b - x))  # [a, x, b]
    gapWithY = max(abs(a - y), abs(b - y))  # [a, y, b]
    return min(gapWithX, gapWithY) <= m

  def _checkMultipleGaps(self, a: int, b: int, m: int, x: int, y: int) -> bool:
    """
    Returns true if it's possible to have at most `m` as the minimized maximum
    difference for a sequence with multiple -1s between two numbers.
    e.g. [a, -1, -1, ..., -1, b] can be filled with x and y.
    """
    ax = abs(a - x)
    ay = abs(a - y)
    bx = abs(b - x)
    by = abs(b - y)
    xy = abs(x - y)
    gapAllX = max(ax, bx)  # [a, x, x, ..., x, b]
    gapAllY = max(ay, by)  # [a, y, y, ..., y, b]
    gapXToY = max(ax, xy, by)  # [a, x, ..., y, b]
    gapYToX = max(ay, xy, bx)  # [a, y, ..., x, b]
    return min(gapAllX, gapAllY, gapXToY, gapYToX) <= m

  def _checkBoundaryGaps(self, a: int, m: int, x: int, y: int) -> bool:
    """
    Returns true if it's possible to have at most `m` as the minimized maximum
    difference for a boundary sequence starting or ending with -1s.
    e.g. [a, -1, -1, ...] or [..., -1, -1, a].
    """
    gapAllX = abs(a - x)  # [x, x, ..., x, a]
    gapAllY = abs(a - y)  # [y, y, ..., y, a]
    return min(gapAllX, gapAllY) <= m
