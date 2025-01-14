class Solution:
  def prisonAfterNDays(self, cells: list[int], n: int) -> list[int]:
    nextDayCells = [0] * len(cells)
    day = 0

    while n > 0:
      n -= 1
      for i in range(1, len(cells) - 1):
        nextDayCells[i] = 1 if cells[i - 1] == cells[i + 1] else 0
      if day == 0:
        firstDayCells = nextDayCells.copy()
      elif nextDayCells == firstDayCells:
        n %= day
      cells = nextDayCells.copy()
      day += 1

    return cells
