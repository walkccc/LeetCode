class Solution:
  def findStrobogrammatic(self, n: int) -> list[str]:
    def helper(n: int, k: int) -> list[str]:
      if n == 0:
        return ['']
      if n == 1:
        return ['0', '1', '8']

      ans = []

      for inner in helper(n - 2, k):
        if n < k:
          ans.append('0' + inner + '0')
        ans.append('1' + inner + '1')
        ans.append('6' + inner + '9')
        ans.append('8' + inner + '8')
        ans.append('9' + inner + '6')

      return ans

    return helper(n, n)
