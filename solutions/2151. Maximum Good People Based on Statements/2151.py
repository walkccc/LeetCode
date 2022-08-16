class Solution:
  def maximumGood(self, statements: List[List[int]]) -> int:
    n = len(statements)
    ans = 0

    def isValid(good: List[int]) -> bool:
      for i, g in enumerate(good):
        if not g:  # i-th person is bad, no need to check
          continue
        for j in range(n):
          if statements[i][j] == 2:
            continue
          if statements[i][j] != good[j]:
            return False
      return True

    def dfs(good: List[int], i: int, count: int) -> None:
      nonlocal ans
      if i == n:
        if isValid(good):
          ans = max(ans, count)
        return

      good.append(0)  # assume i-th person is bad
      dfs(good, i + 1, count)
      good[-1] = 1  # assume i-th person is good
      dfs(good, i + 1, count + 1)
      good.pop()

    dfs([], 0, 0)
    return ans
