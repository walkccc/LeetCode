class Solution:
  def simplifiedFractions(self, n: int) -> list[str]:
    ans = []
    for denominator in range(2, n + 1):
      for numerator in range(1, denominator):
        if math.gcd(denominator, numerator) == 1:
          ans.append(str(numerator) + '/' + str(denominator))
    return ans
