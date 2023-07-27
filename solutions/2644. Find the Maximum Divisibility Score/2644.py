class Solution:
  def maxDivScore(self, nums: List[int], divisors: List[int]) -> int:
    ans = -1
    maxScore = -1

    for divisor in divisors:
      score = sum([1 for num in nums if num % divisor == 0])
      if score > maxScore:
        ans = divisor
        maxScore = score
      elif score == maxScore:
        ans = min(ans, divisor)

    return ans
