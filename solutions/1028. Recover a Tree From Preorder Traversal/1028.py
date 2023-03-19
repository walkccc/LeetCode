class Solution:
  def recoverFromPreorder(self, traversal: str) -> Optional[TreeNode]:
    i = 0

    def recoverFromPreorder(depth: int) -> Optional[TreeNode]:
      nonlocal i
      nDashes = 0
      while i + nDashes < len(traversal) and traversal[i + nDashes] == '-':
        nDashes += 1
      if nDashes != depth:
        return None

      i += depth
      start = i
      while i < len(traversal) and traversal[i].isdigit():
        i += 1

      return TreeNode(int(traversal[start:i]),
                      recoverFromPreorder(depth + 1),
                      recoverFromPreorder(depth + 1))

    return recoverFromPreorder(0)
