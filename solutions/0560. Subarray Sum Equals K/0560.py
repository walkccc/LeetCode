class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        ans = 0
        prefixSum = 0
        count = collections.Counter()
        count[0] = 1

        for num in nums:
            prefixSum += num
            ans += count[prefixSum - k]
            count[prefixSum] += 1

        return ans
