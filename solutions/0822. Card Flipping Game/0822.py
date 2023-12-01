class Solution:
  def flipgame(self, fronts: List[int], backs: List[int]) -> int:
    same = {front
            for front, back in zip(fronts, backs)
            if front == back}
    return min([num for num in fronts + backs
                if num not in same] or [0])
