class Codec:
  def serialize(self, root: 'TreeNode') -> str:
    """Encodes a tree to a single string."""
    s = []

    def preorder(root: 'TreeNode') -> None:
      if not root:
        s.append('n')
        return

      s.append(str(root.val))
      preorder(root.left)
      preorder(root.right)

    preorder(root)
    return ' '.join(s)

  def deserialize(self, data: str) -> 'TreeNode':
    """Decodes your encoded data to tree."""
    q = collections.deque(data.split())

    def preorder() -> 'TreeNode':
      s = q.popleft()
      if s == 'n':
        return None

      root = TreeNode(s)
      root.left = preorder()
      root.right = preorder()
      return root

    return preorder()
