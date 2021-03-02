class Solution:
  def shortestSubarray(self, A: List[int], K: int) -> int:
    n = len(A)

    ans = n + 1
    deque = deque()
    prefix = [0] * (n + 1)

    for i in range(n):
      prefix[i + 1] = A[i] + prefix[i]

    for i in range(n + 1):
      while deque and prefix[i] - prefix[deque[0]] >= K:
        ans = min(ans, i - deque.popleft())
      while deque and prefix[i] <= prefix[deque[-1]]:
        deque.pop()
      deque.append(i)

    return ans if ans <= n else -1
