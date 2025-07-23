class Codec:
  # Encodes an n-ary tree to a binary tree.
  def encode(self, root: 'Node') -> TreeNode | None:
    if not root:
      return None

    rootTreeNode = TreeNode(root.val)
    if root.children:
      rootTreeNode.left = self.encode(root.children[0])

    # The parent for the rest of the children
    currTreeNode = rootTreeNode.left

    # Encode the rest of the children
    for i in range(1, len(root.children)):
      currTreeNode.right = self.encode(root.children[i])
      currTreeNode = currTreeNode.right

    return rootTreeNode

  # Decodes your binary tree to an n-ary tree.
  def decode(self, root: TreeNode | None) -> 'Node':
    if not root:
      return None

    rootNode = Node(root.val, [])
    currTreeNode = root.left

    while currTreeNode:
      rootNode.children.append(self.decode(currTreeNode))
      currTreeNode = currTreeNode.right

    return rootNode
