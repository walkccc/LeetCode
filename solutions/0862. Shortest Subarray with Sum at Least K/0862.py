class Solution:
  def shortestSubarray(self, nums: List[int], k: int) -> int:
    n = len(nums)
    ans = n + 1
    q = collections.deque()
    prefix = [0] + list(itertools.accumulate(nums))

    for i in range(n + 1):
      while q and prefix[i] - prefix[q[0]] >= k:
        ans = min(ans, i - q.popleft())
      while q and prefix[i] <= prefix[q[-1]]:
        q.pop()
      q.append(i)

    return ans if ans <= n else -1
