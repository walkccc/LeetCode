class Solution:
  def increasingTriplet(self, nums: list[int]) -> bool:
    first = math.inf
    second = math.inf

    for num in nums:
      if num <= first:
        first = num
      elif num <= second:  # first < num <= second
        second = num
      else:
        return True  # first < second < num (third)

    return False
