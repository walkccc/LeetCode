class SQL:
  def __init__(self, names: list[str], columns: list[int]):
    self.db: dict[str, list[list[str]]] = collections.defaultdict(list)

  def insertRow(self, name: str, row: list[str]) -> None:
    self.db[name].append(row)

  def deleteRow(self, name: str, rowId: int) -> None:
    pass

  def selectCell(self, name: str, rowId: int, columnId: int) -> str:
    return self.db[name][rowId - 1][columnId - 1]
