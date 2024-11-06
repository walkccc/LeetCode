class Solution:
  def kthSmallestPrimeFraction(self, arr: list[int], k: int) -> list[int]:
    n = len(arr)
    ans = [0, 1]
    l = 0
    r = 1

    while True:
      m = (l + r) / 2
      ans[0] = 0
      count = 0
      j = 1

      for i in range(n):
        while j < n and arr[i] > m * arr[j]:
          j += 1
        count += n - j
        if j == n:
          break
        if ans[0] * arr[j] < ans[1] * arr[i]:
          ans[0] = arr[i]
          ans[1] = arr[j]

      if count < k:
        l = m
      elif count > k:
        r = m
      else:
        return ans
