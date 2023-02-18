class Solution:
  def numMovesStones(self, a: int, b: int, c: int) -> List[int]:
    nums = sorted([a, b, c])

    if nums[2] - nums[0] == 2:
      return [0, 0]
    return [1 if min(nums[1] - nums[0], nums[2] - nums[1]) <= 2 else 2,
            nums[2] - nums[0] - 2]
