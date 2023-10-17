class SQL:
  def __init__(self, names: List[str], columns: List[int]):
    self.db: Dict[str, List[List[str]]] = collections.defaultdict(list)

  def insertRow(self, name: str, row: List[str]) -> None:
    self.db[name].append(row)

  def deleteRow(self, name: str, rowId: int) -> None:
    pass

  def selectCell(self, name: str, rowId: int, columnId: int) -> str:
    return self.db[name][rowId - 1][columnId - 1]
