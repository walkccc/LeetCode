class Solution:
  def maxSlidingWindow(self, nums: list[int], k: int) -> list[int]:
    ans = []
    maxQ = collections.deque()

    for i, num in enumerate(nums):
      while maxQ and maxQ[-1] < num:
        maxQ.pop()
      maxQ.append(num)
      if i >= k and nums[i - k] == maxQ[0]:  # out-of-bounds
        maxQ.popleft()
      if i >= k - 1:
        ans.append(maxQ[0])

    return ans
