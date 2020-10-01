class Solution:
    def findNumberOfLIS(self, nums: List[int]) -> int:
        ans = 0
        maxLength = 0
        length = [1] * len(nums)
        count = [1] * len(nums)

        for i, num in enumerate(nums):
            for j in range(i):
                if nums[j] < num:
                    if length[i] == length[j] + 1:
                        count[i] += count[j]
                    elif length[i] < length[j] + 1:
                        length[i] = length[j] + 1
                        count[i] = count[j]
            if maxLength == length[i]:
                ans += count[i]
            elif maxLength < length[i]:
                maxLength = length[i]
                ans = count[i]

        return ans
