class Solution:
  def permute(self, n: int) -> list[list[int]]:
    ans = []
    used = [False] * (n + 1)

    def dfs(path: list[int]) -> None:
      if len(path) == n:
        ans.append(path.copy())
        return
      for num in range(1, n + 1):
        if used[num]:
          continue
        if path and path[-1] % 2 == num % 2:
          continue
        used[num] = True
        path.append(num)
        dfs(path)
        path.pop()
        used[num] = False

    dfs([])
    return ans
