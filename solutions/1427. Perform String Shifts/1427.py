class Solution:
  def stringShift(self, s: str, shift: List[List[int]]) -> str:
    move = 0

    for direction, amount in shift:
      if direction == 0:
        move -= amount
      else:
        move += amount

    move %= len(s)
    return s[-move:] + s[:-move]
