class Codec:
  # Encodes an n-ary tree to a binary tree.
  def encode(self, root: 'Node') -> Optional[TreeNode]:
    if not root:
      return None

    rootTreeNode = TreeNode(root.val)
    q = collections.deque([(root, rootTreeNode)])

    while q:
      parentNode, parentTreeNode = q.popleft()
      prevTreeNode = None
      headTreeNode = None
      for child in parentNode.children:
        currTreeNode = TreeNode(child.val)
        if prevTreeNode:
          prevTreeNode.right = currTreeNode
        else:
          headTreeNode = currTreeNode
        prevTreeNode = currTreeNode
        q.append((child, currTreeNode))
      parentTreeNode.left = headTreeNode

    return rootTreeNode

  # Decodes your binary tree to an n-ary tree.
  def decode(self, root: Optional[TreeNode]) -> 'Node':
    if not root:
      return None

    rootNode = Node(root.val, [])
    q = collections.deque([(rootNode, root)])

    while q:
      parentNode, parentTreeNode = q.popleft()
      sibling = parentTreeNode.left
      while sibling:
        currNode = Node(sibling.val, [])
        parentNode.children.append(currNode)
        q.append((currNode, sibling))
        sibling = sibling.right

    return rootNode
