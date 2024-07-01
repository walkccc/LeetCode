class Solution:
  def canMerge(self, trees: List[TreeNode]) -> Optional[TreeNode]:
    valToNode = {}  # {val: node}
    count = collections.Counter()  # {val: freq}

    for tree in trees:
      valToNode[tree.val] = tree
      count[tree.val] += 1
      if tree.left:
        count[tree.left.val] += 1
      if tree.right:
        count[tree.right.val] += 1

    def isValidBST(tree: Optional[TreeNode], minNode: Optional[TreeNode], maxNode: Optional[TreeNode]) -> bool:
      if not tree:
        return True
      if minNode and tree.val <= minNode.val:
        return False
      if maxNode and tree.val >= maxNode.val:
        return False
      if not tree.left and not tree.right and tree.val in valToNode:
        val = tree.val
        tree.left = valToNode[val].left
        tree.right = valToNode[val].right
        del valToNode[val]

      return isValidBST(tree.left, minNode, tree) and isValidBST(tree.right, tree, maxNode)

    for tree in trees:
      if count[tree.val] == 1:
        if isValidBST(tree, None, None) and len(valToNode) <= 1:
          return tree
        return None

    return None
