class CBTInserter:
  def __init__(self, root: Optional[TreeNode]):
    self.tree = [root]
    for node in self.tree:
      if node.left:
        self.tree.append(node.left)
      if node.right:
        self.tree.append(node.right)

  def insert(self, v: int) -> int:
    n = len(self.tree)
    self.tree.append(TreeNode(v))
    parent = self.tree[(n - 1) // 2]
    if n & 1:
      parent.left = self.tree[-1]
    else:
      parent.right = self.tree[-1]
    return parent.val

  def get_root(self) -> Optional[TreeNode]:
    return self.tree[0]
