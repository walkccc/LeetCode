class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        def dfs(path: List[int]) -> None:
            if len(path) == len(nums):
                ans.append(path)
                return

            for i in range(len(nums)):
                if used[i]:
                    continue
                used[i] = True
                dfs(path + [nums[i]])
                used[i] = False

        ans = []
        used = [False] * len(nums)

        dfs([])

        return ans
