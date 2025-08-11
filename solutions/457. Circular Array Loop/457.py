class Solution:
  def circularArrayLoop(self, nums: list[int]) -> bool:
    def advance(i: int) -> int:
      return (i + nums[i]) % len(nums)

    if len(nums) < 2:
      return False

    for i, num in enumerate(nums):
      if num == 0:
        continue

      slow = i
      fast = advance(slow)
      while num * nums[fast] > 0 and num * nums[advance(fast)] > 0:
        if slow == fast:
          if slow == advance(slow):
            break
          return True
        slow = advance(slow)
        fast = advance(advance(fast))

      slow = i
      sign = num
      while sign * nums[slow] > 0:
        next = advance(slow)
        nums[slow] = 0
        slow = next

    return False
