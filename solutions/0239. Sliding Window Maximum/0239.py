class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        ans = []
        decreasingQueue = collections.deque()

        for i, num in enumerate(nums):
            while decreasingQueue and num > decreasingQueue[-1]:
                decreasingQueue.pop()
            decreasingQueue.append(num)
            if i >= k - 1:
                ans.append(decreasingQueue[0])
                if nums[i - k + 1] == decreasingQueue[0]:
                    decreasingQueue.popleft()

        return ans
