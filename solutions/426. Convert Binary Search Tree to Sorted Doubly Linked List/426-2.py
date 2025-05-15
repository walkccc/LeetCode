class Solution:
  def treeToDoublyList(self, root: 'Node | None') -> 'Node | None':
    if not root:
      return None

    stack = []
    first = None
    pred = None

    while root or stack:
      while root:
        stack.append(root)
        root = root.left
      root = stack.pop()
      if not first:
        first = root
      if pred:
        pred.right = root
        root.left = pred
      pred = root
      root = root.right

    pred.right = first
    first.left = pred
    return first
