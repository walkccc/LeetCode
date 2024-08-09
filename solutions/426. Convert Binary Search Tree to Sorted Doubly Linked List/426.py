class Solution:
  def treeToDoublyList(self, root: 'Optional[Node]') -> 'Optional[Node]':
    if not root:
      return None
    leftHead = self.treeToDoublyList(root.left)
    rightHead = self.treeToDoublyList(root.right)
    root.left = root
    root.right = root
    return self._connect(self._connect(leftHead, root), rightHead)

  def _connect(self, node1: 'Optional[Node]', node2: 'Optional[Node]') -> 'Optional[Node]':
    if not node1:
      return node2
    if not node2:
      return node1

    tail1 = node1.left
    tail2 = node2.left

    # Connect node1's tail with node2.
    tail1.right = node2
    node2.left = tail1

    # Connect node2's tail with node1.
    tail2.right = node1
    node1.left = tail2
    return node1
