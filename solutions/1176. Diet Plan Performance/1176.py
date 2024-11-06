class Solution:
  def dietPlanPerformance(
      self,
      calories: list[int],
      k: int,
      lower: int,
      upper: int,
  ) -> int:
    ans = 0
    summ = 0

    for i, calorie in enumerate(calories):
      summ += calorie
      if i < k - 1:
        continue
      if i >= k:
        summ -= calories[i - k]
      if summ < lower:
        ans -= 1
      elif summ > upper:
        ans += 1

    return ans
