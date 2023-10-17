class Solution:
  def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
    ans = []
    dq = collections.deque()  # Max queue

    for i, num in enumerate(nums):
      while dq and dq[-1] < num:
        dq.pop()
      dq.append(num)
      if i >= k and nums[i - k] == dq[0]:  # Out of bound
        dq.popleft()
      if i >= k - 1:
        ans.append(dq[0])

    return ans
