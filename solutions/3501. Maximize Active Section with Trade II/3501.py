from dataclasses import dataclass


@dataclass
class Group:
  start: int
  length: int


class SparseTable:
  def __init__(self, nums: list[int]):
    self.n = len(nums)
    # st[i][j] := max(nums[j..j + 2^i - 1])
    self.st = [[0] * (self.n + 1) for _ in range(self.n.bit_length() + 1)]
    self.st[0] = nums.copy()
    for i in range(1, self.n.bit_length() + 1):
      for j in range(self.n - (1 << i) + 1):
        self.st[i][j] = max(
            self.st[i - 1][j],
            self.st[i - 1][j + (1 << (i - 1))])

  def query(self, l: int, r: int) -> int:
    """Returns max(nums[l..r])."""
    i = (r - l + 1).bit_length() - 1
    return max(self.st[i][l], self.st[i][r - (1 << i) + 1])


class Solution:
  def maxActiveSectionsAfterTrade(
      self,
      s: str,
      queries: list[list[int]]
  ) -> list[int]:
    ones = s.count('1')
    zeroGroups, zeroGroupIndex = self._getZeroGroups(s)
    if not zeroGroups:
      return [ones] * len(queries)

    st = SparseTable(self._getZeroMergeLengths(zeroGroups))

    def getMaxActiveSections(l: int, r: int) -> int:
      left = (-1 if zeroGroupIndex[l] == -1
              else (zeroGroups[zeroGroupIndex[l]].length -
                    (l - zeroGroups[zeroGroupIndex[l]].start)))
      right = (-1 if zeroGroupIndex[r] == -1
               else (r - zeroGroups[zeroGroupIndex[r]].start + 1))
      startAdjacentGroupIndex, endAdjacentGroupIndex = self._mapToAdjacentGroupIndices(
          zeroGroupIndex[l] + 1, zeroGroupIndex[r] if s[r] == '1' else zeroGroupIndex[r] - 1)
      activeSections = ones
      if (s[l] == '0' and s[r] == '0' and
              zeroGroupIndex[l] + 1 == zeroGroupIndex[r]):
        activeSections = max(activeSections, ones + left + right)
      elif startAdjacentGroupIndex <= endAdjacentGroupIndex:
        activeSections = max(
            activeSections,
            ones + st.query(startAdjacentGroupIndex, endAdjacentGroupIndex))
      if (s[l] == '0' and
          zeroGroupIndex[l] + 1 <= (zeroGroupIndex[r]
                                    if s[r] == '1' else zeroGroupIndex[r] - 1)):
        activeSections = max(activeSections, ones + left +
                             zeroGroups[zeroGroupIndex[l] + 1].length)
      if (s[r] == '0' and zeroGroupIndex[l] < zeroGroupIndex[r] - 1):
        activeSections = max(activeSections, ones + right +
                             zeroGroups[zeroGroupIndex[r] - 1].length)
      return activeSections

    return [getMaxActiveSections(l, r) for l, r in queries]

  def _getZeroGroups(self, s: str) -> tuple[list[Group], list[int]]:
    """
    Returns the zero groups and the index of the zero group that contains the
    i-th character.
    """
    zeroGroups = []
    zeroGroupIndex = []
    for i in range(len(s)):
      if s[i] == '0':
        if i > 0 and s[i - 1] == '0':
          zeroGroups[-1].length += 1
        else:
          zeroGroups.append(Group(i, 1))
      zeroGroupIndex.append(len(zeroGroups) - 1)
    return zeroGroups, zeroGroupIndex

  def _getZeroMergeLengths(self, zeroGroups: list[Group]) -> list[int]:
    """Returns the sums of the lengths of the adjacent groups."""
    return [a.length + b.length for a, b in itertools.pairwise(zeroGroups)]

  def _mapToAdjacentGroupIndices(
      self,
      startGroupIndex: int,
      endGroupIndex: int
  ) -> tuple[int, int]:
    """
    Returns the indices of the adjacent groups that contain l and r completely.

    e.g.    groupIndices = [0, 1, 2, 3]
    adjacentGroupIndices = [0 (0, 1), 1 (1, 2), 2 (2, 3)]
    map(startGroupIndex = 1, endGroupIndex = 3) -> (1, 2)
    """
    return startGroupIndex, endGroupIndex - 1
