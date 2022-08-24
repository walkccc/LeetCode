class Solution:
  def prisonAfterNDays(self, cells: List[int], N: int) -> List[int]:
    nextDayCells = [0] * len(cells)
    day = 0

    while N > 0:
      N -= 1
      for i in range(1, len(cells) - 1):
        nextDayCells[i] = 1 if cells[i - 1] == cells[i + 1] else 0
      if day == 0:
        firstDayCells = nextDayCells.copy()
      elif nextDayCells == firstDayCells:
        N %= day
      cells = nextDayCells.copy()
      day += 1

    return cells
