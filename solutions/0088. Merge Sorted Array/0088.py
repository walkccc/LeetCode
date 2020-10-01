class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        k = m + n

        while n > 0:
            k -= 1
            if m > 0 and nums1[m - 1] > nums2[n - 1]:
                m -= 1
                nums1[k] = nums1[m]
            else:
                n -= 1
                nums1[k] = nums2[n]
