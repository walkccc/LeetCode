class Solution:
  def canBeEqual(self, target: list[int], arr: list[int]) -> bool:
    return collections.Counter(arr) == collections.Counter(target)
