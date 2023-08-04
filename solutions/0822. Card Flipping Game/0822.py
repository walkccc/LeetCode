class Solution:
  def flipgame(self, fronts: List[int], backs: List[int]) -> int:
    same = {f for f, b in zip(fronts, backs) if f == b}
    return min([num for num in fronts + backs
                if num not in same] or [0])
