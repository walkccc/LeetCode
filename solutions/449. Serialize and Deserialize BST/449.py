class Codec:
  def serialize(self, root: TreeNode | None) -> str:
    """Encodes a tree to a single string."""
    if not root:
      return ''
    chars = []
    self._serialize(root, chars)
    return ''.join(chars)

  def deserialize(self, data: str) -> TreeNode | None:
    """Decodes your encoded data to tree."""
    if not data:
      return None
    q = collections.deque(int(val) for val in data.split())
    return self._deserialize(-math.inf, math.inf, q)

  def _serialize(self, root: TreeNode | None, chars: list[str]) -> None:
    if not root:
      return
    chars.append(str(root.val))
    chars.append(' ')
    self._serialize(root.left, chars)
    self._serialize(root.right, chars)

  def _deserialize(
      self,
      mn: int,
      mx: int,
      q: collections.deque[int]
  ) -> TreeNode | None:
    if not q:
      return None

    val = q[0]
    if val < mn or val > mx:
      return None

    q.popleft()
    return TreeNode(val,
                    self._deserialize(mn, val, q),
                    self._deserialize(val, mx, q))
