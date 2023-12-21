class Solution:
  def minimumRemoval(self, beans: List[int]) -> int:
    n = len(beans)
    summ = sum(beans)
    return min(summ - (n - i) * bean
               for i, bean in enumerate(sorted(beans)))
