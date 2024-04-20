class Solution:
  def bstFromPreorder(self, preorder: List[int]) -> Optional[TreeNode]:
    root = TreeNode(preorder[0])
    stack = [root]

    for i in range(1, len(preorder)):
      parent = stack[-1]
      child = TreeNode(preorder[i])
      # Adjust the parent.
      while stack and stack[-1].val < child.val:
        parent = stack.pop()
      # Create parent-child link according to BST property.
      if parent.val > child.val:
        parent.left = child
      else:
        parent.right = child
      stack.append(child)

    return root
