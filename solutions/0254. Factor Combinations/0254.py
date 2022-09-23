class Solution:
  def getFactors(self, n: int) -> List[List[int]]:
    ans = []

    def dfs(n: int, s: int, path: List[int]) -> None:
      if n <= 1:
        if len(path) > 1:
          ans.append(path.copy())
        return

      for i in range(s, n + 1):
        if n % i == 0:
          path.append(i)
          dfs(n // i, i, path)
          path.pop()

    dfs(n, 2, [])  # the smallest factor is 2
    return ans
