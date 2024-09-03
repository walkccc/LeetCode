class Solution:
  def postorderTraversal(self, root: TreeNode | None) -> list[int]:
    if not root:
      return []

    ans = []
    stack = [root]

    while stack:
      node = stack.pop()
      ans.append(node.val)
      if node.left:
        stack.append(node.left)
      if node.right:
        stack.append(node.right)

    return ans[::-1]
