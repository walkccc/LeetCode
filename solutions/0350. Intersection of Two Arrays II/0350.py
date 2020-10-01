class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        ans = []
        count = collections.Counter(nums1)

        for num in nums2:
            if count[num] > 0:
                ans.append(num)
                count[num] -= 1

        return ans
