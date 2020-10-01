class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        def dfs(path: List[int]) -> None:
            if len(path) == len(nums):
                ans.append(path)
                return

            for i, num in enumerate(nums):
                if used[i]:
                    continue
                if i > 0 and nums[i] == nums[i - 1] and not used[i - 1]:
                    continue
                used[i] = True
                dfs(path + [num])
                used[i] = False

        ans = []
        used = [False] * len(nums)

        nums.sort()
        dfs([])

        return ans
