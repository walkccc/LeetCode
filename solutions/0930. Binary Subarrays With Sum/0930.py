class Solution:
    def numSubarraysWithSum(self, A: List[int], S: int) -> int:
        ans = 0
        prefixSum = 0
        count = collections.Counter({0: 1})

        for a in A:
            prefixSum += a
            ans += count[prefixSum - S]
            count[prefixSum] += 1

        return ans
