class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        leftIndex = self.find(nums, target, True)

        if leftIndex == len(nums) or nums[leftIndex] != target:
            return -1, -1

        return leftIndex, self.find(nums, target, False) - 1

    def find(self, nums: List[int], target: int, isLeft: bool) -> int:
        l = 0
        r = len(nums)

        while l < r:
            m = (l + r) // 2
            if nums[m] > target or (isLeft and nums[m] == target):
                r = m
            else:
                l = m + 1

        return l
