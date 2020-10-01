class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        summ = sum(nums)
        prefixSum = 0

        for i, num in enumerate(nums):
            if prefixSum == summ - prefixSum - num:
                return i
            prefixSum += num

        return -1
