class Solution:
  def maxNumberOfApples(self, weight: List[int]) -> int:
    summ = 0

    for i, w in enumerate(sorted(weight)):
      summ += w
      if summ > 5000:
        return i

    return len(weight)
