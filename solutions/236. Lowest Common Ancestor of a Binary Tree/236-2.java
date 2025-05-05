class Solution {
  public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
    Queue<TreeNode> q_ = new ArrayDeque<>(List.of(root));
    Map<TreeNode, TreeNode> parent = new HashMap<>();
    parent.put(root, null);
    Set<TreeNode> ancestors = new HashSet<>(); // p's ancestors

    // Iterate until we find both p and q.
    while (!parent.containsKey(p) || !parent.containsKey(q)) {
      root = q_.poll();
      if (root.left != null) {
        parent.put(root.left, root);
        q_.offer(root.left);
      }
      if (root.right != null) {
        parent.put(root.right, root);
        q_.offer(root.right);
      }
    }

    // Insert all the p's ancestors.
    while (p != null) {
      ancestors.add(p);
      p = parent.get(p); // `p` becomes null in the end.
    }

    // Go up from q until we meet any of p's ancestors.
    while (!ancestors.contains(q))
      q = parent.get(q);

    return q;
  }
}
