class Solution:
  def numSquarefulPerms(self, A: List[int]) -> int:
    def isSquare(num: int) -> bool:
      root = int(sqrt(num))
      return root * root == num

    def dfs(path: List[int]) -> None:
      if len(path) > 1 and not isSquare(path[-1] + path[-2]):
        return
      if len(path) == len(A):
        self.ans += 1
        return

      for i, a in enumerate(A):
        if used[i]:
          continue
        if i > 0 and A[i] == A[i - 1] and not used[i - 1]:
          continue
        used[i] = True
        dfs(path + [a])
        used[i] = False

    self.ans = 0
    used = [False] * len(A)

    A.sort()
    dfs([])

    return self.ans
