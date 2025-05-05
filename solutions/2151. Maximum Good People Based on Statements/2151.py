class Solution:
  def maximumGood(self, statements: list[list[int]]) -> int:
    n = len(statements)
    ans = 0

    def isValid(good: list[int]) -> bool:
      for i, g in enumerate(good):
        if not g:  # The i-th person is bad, so no need to check.
          continue
        for j in range(n):
          if statements[i][j] == 2:
            continue
          if statements[i][j] != good[j]:
            return False
      return True

    def dfs(good: list[int], i: int, count: int) -> None:
      nonlocal ans
      if i == n:
        if isValid(good):
          ans = max(ans, count)
        return

      good.append(0)  # Assume the i-th person is bad.
      dfs(good, i + 1, count)
      good[-1] = 1  # Assume the i-th person is good.
      dfs(good, i + 1, count + 1)
      good.pop()

    dfs([], 0, 0)
    return ans
