class Solution:
  def findMaxConsecutiveOnes(self, nums: list[int]) -> int:
    maxZeros = 1
    ans = 0
    q = collections.deque()  # Store indices of zero.

    l = 0
    for r, num in enumerate(nums):
      if num == 0:
        q.append(r)
      if len(q) > maxZeros:
        l = q.popleft() + 1
      ans = max(ans, r - l + 1)

    return ans
