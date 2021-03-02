class Solution:
  def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
    ans = []
    q = deque()  # max queue

    for i, num in enumerate(nums):
      while q and q[-1] < num:
        q.pop()
      q.append(num)
      if i >= k and nums[i - k] == q[0]:  # out of bound
        q.popleft()
      if i >= k - 1:
        ans.append(q[0])

    return ans
