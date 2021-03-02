class Solution:
  def maxSum(self, nums1: List[int], nums2: List[int]) -> int:
    ans = 0
    sum1 = 0  # sum of nums1 in (prev rendezvous, next rendezvous)
    sum2 = 0  # sum of nums2 in (prev rendezvous, next rendezvous)
    i = 0     # nums1's index
    j = 0     # nums2's index

    while i < len(nums1) and j < len(nums2):
      if nums1[i] < nums2[j]:
        sum1 += nums1[i]
        i += 1
      elif nums1[i] > nums2[j]:
        sum2 += nums2[j]
        j += 1
      else:  # rendezvous
        ans += max(sum1, sum2) + nums1[i]
        sum1 = 0
        sum2 = 0
        i += 1
        j += 1

    while i < len(nums1):
      sum1 += nums1[i]
      i += 1

    while j < len(nums2):
      sum2 += nums2[j]
      j += 1

    return (ans + max(sum1, sum2)) % (10**9 + 7)
