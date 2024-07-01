class Solution:
  def canBeEqual(self, target: List[int], arr: List[int]) -> bool:
    return collections.Counter(arr) == collections.Counter(target)
