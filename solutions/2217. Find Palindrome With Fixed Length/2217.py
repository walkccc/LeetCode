class Solution:
  def kthPalindrome(self, queries: list[int], intLength: int) -> list[int]:
    start = pow(10, (intLength + 1) // 2 - 1)
    end = pow(10, (intLength + 1) // 2)
    mul = pow(10, intLength // 2)

    def reverse(num: int) -> int:
      res = 0
      while num:
        res = res * 10 + num % 10
        num //= 10
      return res

    def getKthPalindrome(query: int) -> int:
      prefix = start + query - 1
      return prefix * mul + reverse(prefix
                                    if intLength % 2 == 0 else prefix // 10)

    return [-1 if start + query > end else getKthPalindrome(query)
            for query in queries]
