class Solution:
    def constrainedSubsetSum(self, nums: List[int], k: int) -> int:
        ans = float('-inf')
        dp = [0] * len(nums)
        q = collections.deque()

        for i, num in enumerate(nums):
            if q:
                dp[i] = max(q[0], 0) + num
            else:
                dp[i] = num
            ans = max(ans, dp[i])
            while q and q[-1] < dp[i]:
                q.pop()
            q.append(dp[i])
            if i >= k and dp[i - k] == q[0]:
                q.popleft()

        return ans
