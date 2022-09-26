class Solution:
  def kthSmallestProduct(self, nums1: List[int], nums2: List[int], k: int) -> int:
    A1 = [-num for num in nums1 if num < 0][::-1]  # reverse to sort ascending
    A2 = [num for num in nums1 if num >= 0]
    B1 = [-num for num in nums2 if num < 0][::-1]  # reverse to sort ascending
    B2 = [num for num in nums2 if num >= 0]

    negCount = len(A1) * len(B2) + len(A2) * len(B1)

    if k > negCount:  # find (k - negCount)-th positive
      k -= negCount
      sign = 1
    else:
      k = negCount - k + 1  # find (negCount - k + 1)-th abs(negative)
      sign = -1
      B1, B2 = B2, B1

    def numProductNoGreaterThan(A: List[int], B: List[int], m: int) -> int:
      ans = 0
      j = len(B) - 1
      for i in range(len(A)):
        # for each A[i], find the first index j s.t. A[i] * B[j] <= m
        # so numProductNoGreaterThan m for this row will be j + 1
        while j >= 0 and A[i] * B[j] > m:
          j -= 1
        ans += j + 1
      return ans

    l = 0
    r = 10**10

    while l < r:
      m = (l + r) // 2
      if numProductNoGreaterThan(A1, B1, m) + \
              numProductNoGreaterThan(A2, B2, m) >= k:
        r = m
      else:
        l = m + 1

    return sign * l
