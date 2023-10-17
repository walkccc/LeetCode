class Solution:
  def sumFourDivisors(self, nums: List[int]) -> int:
    ans = 0

    for num in nums:
      divisor = 0
      for i in range(2, int(sqrt(num)) + 1):
        if num % i == 0:
          if divisor == 0:
            divisor = i
          else:
            divisor = 0
            break
      if divisor > 0 and divisor * divisor < num:
        ans += 1 + num + divisor + num // divisor

    return ans
