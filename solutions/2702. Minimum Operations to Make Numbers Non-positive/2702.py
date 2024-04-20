class Solution:
  def minOperations(self, nums: list[int], x: int, y: int) -> int:
    def isPossible(m: int) -> bool:
      """
      Returns True if it's possible to make all `nums` <= 0 using m operations.
      """
      # If we want m operations, first decrease all the numbers by y * m. Then
      # we have m operations to select indices to decrease them by x - y.
      return sum(max(0, math.ceil((num - y * m) / (x - y)))
                 for num in nums) <= m

    return bisect.bisect_left(range(max(nums)), True,
                              key=isPossible)
