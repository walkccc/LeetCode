class Solution:
  def minimumTimeRequired(self, jobs: list[int], k: int) -> int:
    ans = sum(jobs)
    times = [0] * k  # times[i] := accumulate time of workers[i]

    # Assign the most time-consuming job first.
    jobs.sort(reverse=True)

    def dfs(s: int) -> None:
      nonlocal ans
      if s == len(jobs):
        ans = min(ans, max(times))
        return
      for i in range(k):
        # There is no need to explore assigning jobs[s] to workers[i] further as
        # it would not yield better results.
        if times[i] + jobs[s] >= ans:
          continue
        times[i] += jobs[s]
        dfs(s + 1)
        times[i] -= jobs[s]
        # It's always non-optimal to have a worker with no jobs.
        if times[i] == 0:
          return

    dfs(0)
    return ans
