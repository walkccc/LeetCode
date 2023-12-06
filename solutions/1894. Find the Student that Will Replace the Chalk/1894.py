class Solution:
  def chalkReplacer(self, chalk: List[int], k: int) -> int:
    k %= sum(chalk)
    if k == 0:
      return 0

    for i, c in enumerate(chalk):
      k -= c
      if k < 0:
        return i
