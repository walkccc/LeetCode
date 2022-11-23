class Cell:
  def __init__(self, val: int, posCount: Optional[Dict[Tuple[int, int], int]]):
    self.val = val
    self.posCount = posCount  # {pos, count}


class Excel:
  def __init__(self, height: int, width: str):
    self.sheet = [[Cell(0, None) for i in range(height)]
                  for _ in range(ord(width) - ord('A') + 1)]

  def set(self, row: int, column: str, val: int) -> None:
    self.sheet[row - 1][ord(column) - ord('A')] = Cell(val, None)

  def get(self, row: int, column: str) -> int:
    cell = self.sheet[row - 1][ord(column) - ord('A')]
    if cell.posCount:
      return sum(self.get(*pos) * freq for pos, freq in cell.posCount.items())
    return cell.val

  def sum(self, row: int, column: str, numbers: List[str]) -> int:
    self.sheet[row - 1][ord(column) - ord('A')].posCount = self._parse(numbers)
    return self.get(row, column)

  def _parse(self, numbers: List[str]):
    count = Counter()
    for n in numbers:
      s, e = n.split(':')[0], n.split(':')[1] if ':' in n else n
      for i in range(int(s[1:]), int(e[1:]) + 1):
        for j in range(ord(s[0]) - ord('A'), ord(e[0]) - ord('A') + 1):
          count[(i, chr(j + ord('A')))] += 1
    return count
