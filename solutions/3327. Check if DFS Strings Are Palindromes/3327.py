class Solution:
  def findAnswer(self, parent: list[int], s: str) -> list[bool]:
    n = len(parent)
    tree = [[] for _ in parent]
    start = [0] * n  # start[i] := the start index of `dfsStr` of node i
    end = [0] * n  # end[i] := the end index of `dfsStr` of node i
    dfsStr = []

    for i in range(1, n):
      tree[parent[i]].append(i)

    self._dfs(tree, 0, 0, s, start, end, dfsStr)
    t = '#'.join('@' + ''.join(dfsStr) + '$')
    p = self._manacher(t)
    return [self._isPalindrome(s, e, p)
            for s, e in zip(start, end)]

  def _dfs(
      self,
      tree: list[list[int]],
      u: int,
      index: int,
      s: str,
      start: list[int],
      end: list[int],
      dfsStr: list[str]
  ) -> int:
    """Returns the start index of the "DFS string" of u's next node."""
    start[u] = index
    for v in tree[u]:
      index = self._dfs(tree, v, index, s, start, end, dfsStr)
    end[u] = index
    dfsStr.append(s[u])
    return index + 1

  def _manacher(self, t: str) -> list[int]:
    """
    Returns an array `p` s.t. `p[i]` is the length of the longest palindrome
    centered at `t[i]`, where `t` is a string with delimiters and sentinels.
    """
    p = [0] * len(t)
    center = 0
    for i in range(1, len(t) - 1):
      rightBoundary = center + p[center]
      mirrorIndex = center - (i - center)
      if rightBoundary > i:
        p[i] = min(rightBoundary - i, p[mirrorIndex])
      # Try to expand the palindrome centered at i.
      while t[i + 1 + p[i]] == t[i - 1 - p[i]]:
        p[i] += 1
      # If a palindrome centered at i expands past `rightBoundary`, adjust
      # the center based on the expanded palindrome.
      if i + p[i] > rightBoundary:
        center = i
    return p

  def _isPalindrome(self, s: int, e: int, p: list[int]) -> bool:
    """
    Returns true if `dfsStr[s..e]` is a palindrome by using the precomputed
    array `p` from the Manacher's algorithm.

    The precomputed array `p` is based on the string `t` with delimiters and
    sentinels. Let `t = '#'.join('@' + dfsStr + '$')`. Then, the center of
    `dfsStr` maps to `t[s + e + 2]` since `dfsStr[s]` maps to `t[2 * s + 2]`
    and `dfsStr[e]` maps to `t[2 * e + 2]`. So, the center of `dfsStr` is
    `t[(2 * s + 2 + 2 * e + 2) / 2] = t[s + e + 2]`.
    """
    length = e - s + 1
    center = s + e + 2
    return p[center] >= length
