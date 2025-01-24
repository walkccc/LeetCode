class Solution:
  def __init__(self):
    self.kBase = 165_131
    self.kHash = 8_417_508_174_513

  def longestCommonSubpath(self, n: int, paths: list[list[int]]) -> int:
    l = 0
    r = len(paths[0])

    while l < r:
      m = l + (r - l + 1) // 2
      if self._checkCommonSubpath(paths, m):
        l = m
      else:
        r = m - 1

    return l

  def _checkCommonSubpath(self, paths: list[list[int]], m: int) -> bool:
    """
    Returns True if there's a common subpath of length m for all the paths.
    """
    # Calculate the hash values for subpaths of length m for every path.
    hashSets = [self._rabinKarp(path, m) for path in paths]

    # Check if there is a common subpath of length m.
    for subpathHash in hashSets[0]:
      if all(subpathHash in hashSet for hashSet in hashSets):
        return True

    return False

  def _rabinKarp(self, path: list[int], m: int) -> set[int]:
    """Returns the hash values for subpaths of length m in the path."""
    hashes = set()
    maxPower = 1
    hash = 0

    for i, num in enumerate(path):
      hash = (hash * self.kBase + num) % self.kHash
      if i >= m:
        hash = (hash - path[i - m] * maxPower %
                self.kHash + self.kHash) % self.kHash
      else:
        maxPower = maxPower * self.kBase % self.kHash
      if i >= m - 1:
        hashes.add(hash)

    return hashes
