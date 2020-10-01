class Solution:
    def findBestValue(self, arr: List[int], target: int) -> int:
        prefixSum = 0

        arr.sort()

        for i, a in enumerate(arr):
            ans = round((target - prefixSum) / (len(arr) - i))
            if ans <= a:
                return ans
            prefixSum += a

        return arr[-1]
