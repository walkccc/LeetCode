class Solution:
  def maxProfitAssignment(self, difficulty: List[int], profit: List[int], worker: List[int]) -> int:
    ans = 0
    jobs = sorted(zip(difficulty, profit))
    worker.sort(reverse=1)

    i = 0
    maxProfit = 0

    for w in sorted(worker):
      while i < len(jobs) and w >= jobs[i][0]:
        maxProfit = max(maxProfit, jobs[i][1])
        i += 1
      ans += maxProfit

    return ans
