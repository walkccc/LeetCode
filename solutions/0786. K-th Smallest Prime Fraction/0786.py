class Solution:
  def kthSmallestPrimeFraction(self, A: List[int], K: int) -> List[int]:
    n = len(A)
    ans = [0, 1]
    l = 0
    r = 1

    while True:
      m = (l + r) / 2
      ans[0] = 0
      count = 0
      j = 1

      for i in range(n):
        while j < n and A[i] > m * A[j]:
          j += 1
        count += n - j
        if j == n:
          break
        if ans[0] * A[j] < ans[1] * A[i]:
          ans[0] = A[i]
          ans[1] = A[j]

      if count < K:
        l = m
      elif count > K:
        r = m
      else:
        return ans
