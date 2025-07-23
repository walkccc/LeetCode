from dataclasses import dataclass


@dataclass(frozen=True)
class T:
  isPerfect: bool
  sz: int


class Solution:
  def kthLargestPerfectSubtree(self, root: TreeNode | None, k: int) -> int:
    ans = []
    self._dfs(root, ans)
    if len(ans) < k:
      return -1
    return sorted(ans, reverse=True)[k - 1]

  def _dfs(self, root: TreeNode, ans: list[int]) -> T:
    if not root:
      return T(True, 0)
    l = self._dfs(root.left, ans)
    r = self._dfs(root.right, ans)
    if l.isPerfect and r.isPerfect and l.sz == r.sz:
      sz = 1 + l.sz + r.sz
      ans.append(sz)
      return T(True, sz)
    return T(False, 0)
