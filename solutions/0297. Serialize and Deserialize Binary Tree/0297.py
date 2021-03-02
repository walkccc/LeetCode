class Codec:
  def serialize(self, root: 'TreeNode') -> str:
    """
    Encodes a tree to a single string.
    """
    if not root:
      return ""

    s = ''
    q = deque([root])

    while q:
      root = q.popleft()
      if root:
        s += str(root.val) + ' '
        q.append(root.left)
        q.append(root.right)
      else:
        s += 'n '

    return s

  def deserialize(self, data: str) -> 'TreeNode':
    """
    Decodes your encoded data to tree.
    """
    if not data:
      return None

    vals = data.split()
    root = TreeNode(int(vals[0]))
    q = deque([root])

    i = 1
    while i < len(vals):
      parent = q.popleft()
      if vals[i] != 'n':
        left = TreeNode(int(vals[i]))
        parent.left = left
        q.append(left)
      i += 1
      if vals[i] != 'n':
        right = TreeNode(int(vals[i]))
        parent.right = right
        q.append(right)
      i += 1

    return root
