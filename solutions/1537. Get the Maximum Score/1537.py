class Solution:
  def maxSum(self, nums1: List[int], nums2: List[int]) -> int:
    # Keep the running the sum of `nums1` and `nums2` before the next rendezvous.
    # Since `nums1` and `nums2` are increasing, move forward on the smaller one
    # to ensure we don't miss any rendezvous. When meet rendezvous, choose the
    # better path.
    ans = 0
    sum1 = 0  # sum(nums1) in (the prevoious rendezvous, the next rendezvous)
    sum2 = 0  # sum(nums2) in (the prevoious rendezvous, the next rendezvous)
    i = 0  # nums1's index
    j = 0  # nums2's index

    while i < len(nums1) and j < len(nums2):
      if nums1[i] < nums2[j]:
        sum1 += nums1[i]
        i += 1
      elif nums1[i] > nums2[j]:
        sum2 += nums2[j]
        j += 1
      else:  # An rendezvous happens.
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
