class Solution:
  def minimumDifference(self, nums: List[int]) -> int:
    n = len(nums) // 2
    summ = sum(nums)
    goal = summ // 2
    lNums = nums[:n]
    rNums = nums[n:]
    ans = abs(sum(lNums) - sum(rNums))
    lSums = [[] for _ in range(n + 1)]
    rSums = [[] for _ in range(n + 1)]

    def dfs(A: List[int], i: int, count: int, path: int, sums: List[List[int]]):
      if i == len(A):
        sums[count].append(path)
        return
      dfs(A, i + 1, count + 1, path + A[i], sums)
      dfs(A, i + 1, count, path, sums)

    dfs(lNums, 0, 0, 0, lSums)
    dfs(rNums, 0, 0, 0, rSums)

    for lCount in range(n):
      l = lSums[lCount]
      r = rSums[n - lCount]
      r.sort()
      for lSum in l:
        i = bisect_left(r, goal - lSum)
        if i < len(r):
          sumPartOne = summ - lSum - r[i]
          sumPartTwo = summ - sumPartOne
          ans = min(ans, abs(sumPartOne - sumPartTwo))
        if i > 0:
          sumPartOne = summ - lSum - r[i - 1]
          sumPartTwo = summ - sumPartOne
          ans = min(ans, abs(sumPartOne - sumPartTwo))

    return ans
