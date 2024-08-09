class Solution:
  def maximumRemovals(self, s: str, p: str, removable: List[int]) -> int:
    l = 0
    r = len(removable) + 1

    def remove(k: int) -> str:
      removed = [c for c in s]
      for i in range(k):
        removed[removable[i]] = '*'
      return ''.join(removed)

    def isSubsequence(p: str, s: str) -> bool:
      i = 0
      for j, c in enumerate(s):
        if p[i] == s[j]:
          i += 1
          if i == len(p):
            return True
      return False

    while l < r:
      m = (l + r) // 2
      removed = remove(m)
      if isSubsequence(p, removed):
        l = m + 1
      else:
        r = m

    return l - 1
