class Solution:
  def numberOfArrays(
      self,
      differences: list[int],
      lower: int,
      upper: int,
  ) -> int:
    prefix = list(itertools.accumulate(differences, initial=0))
    return max(0, (upper - lower) - (max(prefix) - min(prefix)) + 1)
