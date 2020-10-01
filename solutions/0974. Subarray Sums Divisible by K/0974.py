class Solution:
    def subarraysDivByK(self, A: List[int], K: int) -> int:
        ans = 0
        prefixSum = 0
        count = [1] + [0] * (K - 1)

        for a in A:
            prefixSum = (prefixSum + a) % K
            ans += count[prefixSum]
            count[prefixSum] += 1

        return ans
