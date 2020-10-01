class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        ans = 0
        numsSet = set(nums)

        for num in nums:
            if num - 1 not in numsSet:
                length = 0
                while num in numsSet:
                    num += 1
                    length += 1
                ans = max(ans, length)

        return ans
