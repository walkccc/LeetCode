class Solution:
  def boundaryOfBinaryTree(self, root: Optional[TreeNode]) -> List[int]:
    if root is None:
      return []

    ans = [root.val]

    def dfs(root: Optional[TreeNode], lb: bool, rb: bool):
      """
      1. root.left is left boundary if root is left boundary
      root.right if left boundary if root.left is None
      2. same applys for right boundary
      3. if root is left boundary, add it before 2 children - preorder
      if root is right boundary, add it after 2 children - postorder
      4. a leaf that is neighter left/right boundary belongs to the bottom
      """
      if not root:
        return
      if lb:
        ans.append(root.val)
      if not lb and not rb and not root.left and not root.right:
        ans.append(root.val)

      dfs(root.left, lb, rb and not root.right)
      dfs(root.right, lb and not root.left, rb)
      if rb:
        ans.append(root.val)

    dfs(root.left, True, False)
    dfs(root.right, False, True)
    return ans
