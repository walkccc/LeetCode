class Solution:
  def elementInNums(
      self,
      nums: list[int],
      queries: list[list[int]],
  ) -> list[int]:
    n = len(nums)

    def f(time: int, index: int) -> int:
      if time < n:  # [0, 1, 2] -> [1, 2] -> [2]
        index += time
        return -1 if index >= n else nums[index]
      else:  # [] -> [0] -> [0, 1]
        return -1 if index >= time - n else nums[index]

    return [f(time % (2 * n), index) for time, index in queries]
