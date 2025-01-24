class Solution:
  def minAbsDifference(self, nums: list[int], goal: int) -> int:
    n = len(nums) // 2
    ans = math.inf
    lSums = []
    rSums = []

    def dfs(A: list[int], i: int, path: int, sums: list[int]) -> None:
      if i == len(A):
        sums.append(path)
        return
      dfs(A, i + 1, path + A[i], sums)
      dfs(A, i + 1, path, sums)

    dfs(nums[:n], 0, 0, lSums)
    dfs(nums[n:], 0, 0, rSums)
    rSums.sort()

    for lSum in lSums:
      i = bisect_left(rSums, goal - lSum)
      if i < len(rSums):  # 2^n
        ans = min(ans, abs(goal - lSum - rSums[i]))
      if i > 0:
        ans = min(ans, abs(goal - lSum - rSums[i - 1]))

    return ans
