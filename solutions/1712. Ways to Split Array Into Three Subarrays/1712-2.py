class Solution:
  def waysToSplit(self, nums: List[int]) -> int:
    kMod = 1_000_000_007
    n = len(nums)
    ans = 0
    prefix = list(itertools.accumulate(nums))

    j = 0
    k = 0
    for i in range(n - 2):
      # find the first index j s.t.
      # left = prefix[i] <= mid = prefix[j] - prefix[i]
      j = max(j, i + 1)
      while j < n - 1 and prefix[i] > prefix[j] - prefix[i]:
        j += 1
      # find the first index k s.t.
      # mid = prefix[k] - prefix[i] > right = prefix[-1] - prefix[k]
      k = max(k, j)
      while k < n - 1 and prefix[k] - prefix[i] <= prefix[-1] - prefix[k]:
        k += 1
      ans += k - j
      ans %= kMod

    return ans
