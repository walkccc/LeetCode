class Solution:
  def minAbsoluteSumDiff(self, nums1: List[int], nums2: List[int]) -> int:
    ans = math.inf
    diffs = [abs(a - b) for a, b in zip(nums1, nums2)]
    sumDiff = sum(diffs)

    nums1.sort()

    for num, diff in zip(nums2, diffs):
      i = bisect.bisect_left(nums1, num)
      if i > 0:
        ans = min(ans, sumDiff - diff + abs(num - nums1[i - 1]))
      if i < len(nums1):
        ans = min(ans, sumDiff - diff + abs(num - nums1[i]))

    return ans % int(1e9 + 7)
