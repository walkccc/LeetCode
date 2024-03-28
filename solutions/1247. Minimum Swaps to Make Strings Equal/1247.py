class Solution:
  def minimumSwap(self, s1: str, s2: str) -> int:
    # ('xx', 'yy') = (2 'xy's) . 1 swap
    # ('yy', 'xx') = (2 'yx's) . 1 swap
    # ('xy', 'yx') = (1 'xy' and 1 'yx') . 2 swaps
    xy = 0  # the number of indices i's s.t. s1[i] = 'x' and s2[i] 'y'
    yx = 0  # the number of indices i's s.t. s1[i] = 'y' and s2[i] 'x'

    for a, b in zip(s1, s2):
      if a == b:
        continue
      if a == 'x':
        xy += 1
      else:
        yx += 1

    if (xy + yx) % 2 == 1:
      return -1
    return xy // 2 + yx // 2 + (2 if xy % 2 == 1 else 0)
