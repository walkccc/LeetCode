class Solution {
  public int findClosestLeaf(TreeNode root, int k) {
    ans = -1;
    minDist = 1000;
    // {node: distance to TreeNode(k)}
    Map<TreeNode, Integer> nodeToDist = new HashMap<>();

    getDists(root, k, nodeToDist);
    getClosestLeaf(root, 0, nodeToDist);

    return ans;
  }

  private int ans;
  private int minDist;

  private void getDists(TreeNode root, int k, Map<TreeNode, Integer> nodeToDist) {
    if (root == null)
      return;
    if (root.val == k) {
      nodeToDist.put(root, 0);
      return;
    }

    getDists(root.left, k, nodeToDist);
    if (nodeToDist.containsKey(root.left)) {
      // the TreeNode(k) is in the left subtree
      nodeToDist.put(root, nodeToDist.get(root.left) + 1);
      return;
    }

    getDists(root.right, k, nodeToDist);
    if (nodeToDist.containsKey(root.right))
      // the TreeNode(k) is in the right subtree
      nodeToDist.put(root, nodeToDist.get(root.right) + 1);
  }

  private void getClosestLeaf(TreeNode root, int dist, Map<TreeNode, Integer> nodeToDist) {
    if (root == null)
      return;
    if (nodeToDist.containsKey(root))
      dist = nodeToDist.get(root);
    if (root.left == null && root.right == null) {
      if (dist < minDist) {
        minDist = dist;
        ans = root.val;
      }
      return;
    }

    getClosestLeaf(root.left, dist + 1, nodeToDist);
    getClosestLeaf(root.right, dist + 1, nodeToDist);
  }
}
