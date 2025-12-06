from collections import deque
from typing import List

class Solution:
    def countPartitions(self, nums: List[int], k: int) -> int:
        n = len(nums)
        MOD = 10**9 + 7
        
        dp = [0] * (n + 1)
        dp[0] = 1
        
        prefix_sum = [0] * (n + 2)
        prefix_sum[1] = 1
        
        max_dq = deque()
        min_dq = deque()
        j = 0
        
        for i in range(1, n + 1):
            val = nums[i - 1]
            
            while max_dq and nums[max_dq[-1]] <= val:
                max_dq.pop()
            max_dq.append(i - 1)
            
            while min_dq and nums[min_dq[-1]] >= val:
                min_dq.pop()
            min_dq.append(i - 1)
            
            while nums[max_dq[0]] - nums[min_dq[0]] > k:
                if max_dq[0] == j:
                    max_dq.popleft()
                if min_dq[0] == j:
                    min_dq.popleft()
                j += 1
            
            count = (prefix_sum[i] - prefix_sum[j]) % MOD
            dp[i] = count
            prefix_sum[i + 1] = (prefix_sum[i] + count) % MOD
            
        return dp[n]