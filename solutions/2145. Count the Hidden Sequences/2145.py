class Solution:
  def numberOfArrays(self, differences: List[int], lower: int, upper: int) -> int:
    prefix = [0] + list(accumulate(differences))
    return max(0, (upper - lower) - (max(prefix) - min(prefix)) + 1)
