class Solution:
  def selfDivisiblePermutationCount(self, n: int) -> int:
    def dfs(num: int, used: int) -> int:
      if num > n:
        return 1

      count = 0
      for i in range(1, n + 1):
        if (used >> i & 1) == 0 and (num % i == 0 or i % num == 0):
          count += dfs(num + 1, used | 1 << i)

      return count

    return dfs(1, 0)
