class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        prefixSum = 0
        prefixSumToIndex = {0: -1}

        for i, num in enumerate(nums):
            prefixSum += num
            if k != 0:
                prefixSum %= k
            if prefixSum in prefixSumToIndex:
                if i - prefixSumToIndex[prefixSum] > 1:
                    return True
            else:
                prefixSumToIndex[prefixSum] = i

        return False
