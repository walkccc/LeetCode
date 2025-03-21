class Solution {
  public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
    List<Integer> ans = new ArrayList<>();
    Map<TreeNode, Integer> nodeToDist = new HashMap<>(); // {node: distance to target}

    getDists(root, target, nodeToDist);
    dfs(root, k, 0, nodeToDist, ans);

    return ans;
  }

  private void getDists(TreeNode root, TreeNode target, Map<TreeNode, Integer> nodeToDist) {
    if (root == null)
      return;
    if (root == target) {
      nodeToDist.put(root, 0);
      return;
    }

    getDists(root.left, target, nodeToDist);
    if (nodeToDist.containsKey(root.left)) {
      // The target is in the left subtree.
      nodeToDist.put(root, nodeToDist.get(root.left) + 1);
      return;
    }

    getDists(root.right, target, nodeToDist);
    if (nodeToDist.containsKey(root.right))
      // The target is in the right subtree.
      nodeToDist.put(root, nodeToDist.get(root.right) + 1);
  }

  private void dfs(TreeNode root, int k, int dist, Map<TreeNode, Integer> nodeToDist,
                   List<Integer> ans) {
    if (root == null)
      return;
    if (nodeToDist.containsKey(root))
      dist = nodeToDist.get(root);
    if (dist == k)
      ans.add(root.val);

    dfs(root.left, k, dist + 1, nodeToDist, ans);
    dfs(root.right, k, dist + 1, nodeToDist, ans);
  }
}
