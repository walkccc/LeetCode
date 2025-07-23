class Solution:
  def __init__(self, nums: list[int]):
    self.nums = nums

  def pick(self, target: int) -> int:
    ans = -1
    rng = 0
    for i, num in enumerate(self.nums):
      if num == target:
        rng += 1
        if random.randint(0, rng - 1) == 0:
          ans = i
    return ans
