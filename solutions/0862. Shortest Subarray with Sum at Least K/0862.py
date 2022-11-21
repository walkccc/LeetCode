class Solution:
  def shortestSubarray(self, A: List[int], K: int) -> int:
    n = len(A)
    ans = n + 1
    q = deque()
    prefix = [0] + list(itertools.accumulate(A))

    for i in range(n + 1):
      while q and prefix[i] - prefix[q[0]] >= K:
        ans = min(ans, i - q.popleft())
      while q and prefix[i] <= prefix[q[-1]]:
        q.pop()
      q.append(i)

    return ans if ans <= n else -1
