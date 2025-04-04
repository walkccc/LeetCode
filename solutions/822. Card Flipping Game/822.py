class Solution:
  def flipgame(self, fronts: list[int], backs: list[int]) -> int:
    same = {front
            for front, back in zip(fronts, backs)
            if front == back}
    return min([num for num in fronts + backs
                if num not in same] or [0])
