class Solution:
    def longestWPI(self, hours: List[int]) -> int:
        ans = 0
        prefixSum = 0
        dict = {}

        for i in range(len(hours)):
            prefixSum += 1 if hours[i] > 8 else -1
            if prefixSum > 0:
                ans = i + 1
            else:
                if prefixSum not in dict:
                    dict[prefixSum] = i
                if prefixSum - 1 in dict:
                    ans = max(ans, i - dict[prefixSum - 1])

        return ans
