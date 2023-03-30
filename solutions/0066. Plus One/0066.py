class Solution:
  def plusOne(self, digits: List[int]) -> List[int]:
    for i, d in reversed(list(enumerate(digits))):
      if d < 9:
        digits[i] += 1
        return digits
      digits[i] = 0

    return [1] + digits
