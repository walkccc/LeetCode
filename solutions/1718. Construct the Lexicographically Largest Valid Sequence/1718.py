class Solution:
  def constructDistancedSequence(self, n: int) -> List[int]:
    ans = [0] * (2 * n - 1)

    def dfs(i: int, mask: int) -> bool:
      if i == len(ans):
        return True
      if ans[i] > 0:
        return dfs(i + 1, mask)

      # Greedily fill in the `ans` in descending order.
      for num in range(n, 0, -1):
        if (mask >> num & 1) == 1:
          continue
        if num == 1:
          ans[i] = num
          if dfs(i + 1, mask | 1 << num):
            return True
          ans[i] = 0
        else:  # num in [2, n]
          if i + num >= len(ans) or ans[i + num] > 0:
            continue
          ans[i] = num
          ans[i + num] = num
          if dfs(i + 1, mask | 1 << num):
            return True
          ans[i + num] = 0
          ans[i] = 0

      return False

    dfs(0, 0)
    return ans
