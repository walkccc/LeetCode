class Solution:
  def numTriplets(self, nums1: list[int], nums2: list[int]) -> int:
    def countTriplets(A: list[int], B: list[int]):
      """Returns the number of triplet (i, j, k) if A[i]^2 == B[j] * B[k]."""
      res = 0
      count = collections.Counter(B)

      for a in A:
        target = a * a
        for b, freq in count.items():
          if target % b > 0 or target // b not in count:
            continue
          if target // b == b:
            res += freq * (freq - 1)
          else:
            res += freq * count[target // b]

      return res // 2

    return countTriplets(nums1, nums2) + countTriplets(nums2, nums1)
