class Solution:
  def checkArray(self, nums: list[int], k: int) -> bool:
    if k == 1:
      return True

    needDecrease = 0
    # Store nums[i - k + 1..i] with decreasing nums[i - k + 1].
    dq = collections.deque()

    for i, num in enumerate(nums):
      if i >= k:
        needDecrease -= dq.popleft()
      if nums[i] < needDecrease:
        return False
      decreasedNum = nums[i] - needDecrease
      dq.append(decreasedNum)
      needDecrease += decreasedNum

    return dq[-1] == 0
