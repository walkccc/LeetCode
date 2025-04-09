from dataclasses import dataclass


@dataclass
class Cell:
  val: int = 0
  posCount: dict[tuple[int, int], int] | None = None


class Excel:
  def __init__(self, height: int, width: str):
    self.width = ord(width) - ord('A') + 1
    self.sheet = [[Cell() for _ in range(self.width)] for _ in range(height)]

  def set(self, row: int, column: str, val: int) -> None:
    self._getCell(row, column).val = val
    self._getCell(row, column).posCount = {}

  def get(self, row: int, column: str) -> int:
    cell = self._getCell(row, column)
    if not cell.posCount:
      return cell.val
    val = 0
    for pos, count in cell.posCount.items():
      val += self.get(pos // self.width + 1, chr(pos %
                      self.width + ord('A'))) * count
    return val

  def sum(self, row: int, column: str, numbers: list[str]) -> int:
    self._getCell(row, column).posCount = self._parse(numbers)
    return self.get(row, column)

  def _getCell(self, row: int, column: str) -> Cell:
    return self.sheet[row - 1][ord(column) - ord('A')]

  def _parse(self, numbers: list[str]) -> dict[int, int]:
    count: dict[int, int] = {}
    for s in numbers:
      startRow, startCol, endRow, endCol = self._parseRange(s)
      for i in range(startRow - 1, endRow):
        for j in range(ord(startCol) - ord('A'), ord(endCol) - ord('A') + 1):
          pos = i * self.width + j
          count[pos] = count.get(pos, 0) + 1
    return count

  def _parseRange(self, s: str) -> tuple[int, str, int, str]:
    if ':' not in s:
      return int(s[1:]), s[0], int(s[1:]), s[0]
    l, r = s.split(':')
    return int(l[1:]), l[0], int(r[1:]), r[0]
