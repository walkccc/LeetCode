class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        ans = 0
        prefixSum = 0
        prefixSumToIndex = {0: -1}

        for i, num in enumerate(nums):
            prefixSum += 1 if num else -1
            if prefixSum in prefixSumToIndex:
                ans = max(ans, i - prefixSumToIndex[prefixSum])
            else:
                prefixSumToIndex[prefixSum] = i

        return ans
