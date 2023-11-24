class Solution:
  def alternateDigitSum(self, n: int) -> int:
    ans = 0
    sign = 1

    while n > 0:
      sign *= -1
      ans += n % 10 * sign
      n //= 10

    return sign * ans
