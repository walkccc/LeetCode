class Solution:
  def checkArray(self, nums: List[int], k: int) -> bool:
    if k == 1:
      return True

    needDecrease = 0
    # Store nums[i - k + 1..i] with decreasing nums[i - k + 1].
    q = collections.deque()

    for i, num in enumerate(nums):
      if i >= k:
        needDecrease -= q.popleft()
      if nums[i] < needDecrease:
        return False
      decreasedNum = nums[i] - needDecrease
      q.append(decreasedNum)
      needDecrease += decreasedNum

    return q[-1] == 0
