class Solution:
  def waysToSplit(self, nums: List[int]) -> int:
    kMod = 1_000_000_007
    n = len(nums)
    ans = 0
    prefix = list(itertools.accumulate(nums))

    # find the first index j s.t.
    # mid = prefix[j] - prefix[i] >= left = prefix[i]
    def firstGreaterEqual(i: int) -> int:
      l = i + 1
      r = n - 1
      while l < r:
        m = (l + r) // 2
        if prefix[m] - prefix[i] >= prefix[i]:
          r = m
        else:
          l = m + 1
      return l

    # find the first index k s.t.
    # mid = prefix[k] - prefix[i] > right = prefix[-1] - prefix[k]
    def firstGreater(i: int) -> int:
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
