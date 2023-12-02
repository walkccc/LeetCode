class Solution:
  def waysToSplit(self, nums: List[int]) -> int:
    kMod = 1_000_000_007
    n = len(nums)
    ans = 0
    prefix = list(itertools.accumulate(nums))

    def firstGreaterEqual(i: int) -> int:
      """Finds the first index j s.t.
         Mid = prefix[j] - prefix[i] >= left = prefix[i]
      """
      l = i + 1
      r = n - 1
      while l < r:
        m = (l + r) // 2
        if prefix[m] - prefix[i] >= prefix[i]:
          r = m
        else:
          l = m + 1
      return l

    def firstGreater(i: int) -> int:
      """Finds the first index k s.t.
         mid = prefix[k] - prefix[i] > right = prefix[-1] - prefix[k]
      """
      l = i + 1
      r = n - 1
      while l < r:
        m = (l + r) // 2
        if prefix[m] - prefix[i] > prefix[-1] - prefix[m]:
          r = m
        else:
          l = m + 1
      return l

    for i in range(n - 2):
      j = firstGreaterEqual(i)
      if j == n - 1:
        break
      mid = prefix[j] - prefix[i]
      right = prefix[-1] - prefix[j]
      if mid > right:
        continue
      k = firstGreater(i)
      ans = (ans + k - j) % kMod

    return ans
