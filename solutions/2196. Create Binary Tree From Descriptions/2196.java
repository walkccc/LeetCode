class Solution {
  public TreeNode createBinaryTree(int[][] descriptions) {
    Map<TreeNode, TreeNode> childToParent = new HashMap<>();
    Map<Integer, TreeNode> valToNode = new HashMap<>();

    for (int[] d : descriptions) {
      final int p = d[0];
      final int c = d[1];
      final int isLeft = d[2];
      var parent = valToNode.getOrDefault(p, new TreeNode(p));
      var child = valToNode.getOrDefault(c, new TreeNode(c));
      valToNode.put(p, parent);
      valToNode.put(c, child);
      childToParent.put(child, parent);
      if (isLeft == 1)
        parent.left = child;
      else
        parent.right = child;
    }

    // pick a random node and traverse upwardly
    var root = childToParent.keySet().iterator().next();
    while (childToParent.containsKey(root))
      root = childToParent.get(root);
    return root;
  }
}
