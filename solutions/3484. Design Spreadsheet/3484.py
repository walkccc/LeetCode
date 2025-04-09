class Spreadsheet:
  def __init__(self, rows: int) -> None:
    self.spreadsheet = {}

  def setCell(self, cell: str, value: int) -> None:
    self.spreadsheet[cell] = value

  def resetCell(self, cell: str) -> None:
    self.spreadsheet[cell] = 0

  def getValue(self, formula: str) -> int:
    i = formula.find('+')
    return self._getToken(formula[1:i]) + self._getToken(formula[i+1:])

  def _getToken(self, token: str) -> int:
    return int(token) if token[0].isdigit() else self.spreadsheet.get(token, 0)
