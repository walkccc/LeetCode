class UnionFind:
  def __init__(self):
    self.id = {}

  def union(self, u: int, v: int) -> None:
    self.id.setdefault(u, u)
    self.id.setdefault(v, v)
    i = self._find(u)
    j = self._find(v)
    if i != j:
      self.id[i] = j

  def getGroupIdToValues(self) -> Dict[int, List[int]]:
    groupIdToValues = collections.defaultdict(list)
    for u in self.id.keys():
      groupIdToValues[self._find(u)].append(u)
    return groupIdToValues

  def _find(self, u: int) -> int:
    if self.id[u] != u:
      self.id[u] = self._find(self.id[u])
    return self.id[u]


class Solution:
  def matrixRankTransform(self, matrix: List[List[int]]) -> List[List[int]]:
    m = len(matrix)
    n = len(matrix[0])
    ans = [[0] * n for _ in range(m)]
    # {val: [(i, j)]}
    valToGrids = collections.defaultdict(list)
    # rank[i] := the maximum rank of the row or column so far
    maxRankSoFar = [0] * (m + n)

    for i, row in enumerate(matrix):
      for j, val in enumerate(row):
        valToGrids[val].append((i, j))

    for _, grids in sorted(valToGrids.items()):
      uf = UnionFind()
      for i, j in grids:
        # Union i-th row with j-th col.
        uf.union(i, j + m)
      for values in uf.getGroupIdToValues().values():
        # Get the maximum rank of all the included rows and columns.
        maxRank = max(maxRankSoFar[i] for i in values)
        for i in values:
          # Update all the rows and columns to maxRank + 1.
          maxRankSoFar[i] = maxRank + 1
      for i, j in grids:
        ans[i][j] = maxRankSoFar[i]

    return ans
