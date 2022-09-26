class Solution:
  def kLengthApart(self, nums: List[int], k: int) -> bool:
    if k == 0:
      return True

    n = len(nums)

    curr = 0
    next = 1

    while curr < n and next < n:
      if nums[next] == 1:
        if nums[curr] == 1 and next - curr <= k:
          return False
        curr = next
      next += 1

    return True
