class Solution:
  def minimumTime(self, jobs: List[int], workers: List[int]) -> int:
    ans = 0

    jobs.sort()
    workers.sort()

    for job, worker in zip(jobs, workers):
      ans = max(ans, (job - 1) // worker + 1)

    return ans
