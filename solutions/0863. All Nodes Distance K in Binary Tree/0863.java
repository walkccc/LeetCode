class Solution {
  public List<Integer> distanceK(TreeNode root, TreeNode target, int K) {
    List<Integer> ans = new ArrayList<>();
    Map<TreeNode, Integer> nodeToDistance = new HashMap<>();

    findDistance(root, target, nodeToDistance);
    dfs(root, K, 0, nodeToDistance, ans);

    return ans;
  }

  private void findDistance(TreeNode root, TreeNode target, Map<TreeNode, Integer> nodeToDistance) {
    if (root == null)
      return;
    if (root == target) {
      nodeToDistance.put(root, 0);
      return;
    }

    findDistance(root.left, target, nodeToDistance);
    if (nodeToDistance.containsKey(root.left)) {
      nodeToDistance.put(root, nodeToDistance.get(root.left) + 1);
      return;
    }

    findDistance(root.right, target, nodeToDistance);
    if (nodeToDistance.containsKey(root.right)) {
      nodeToDistance.put(root, nodeToDistance.get(root.right) + 1);
      return;
    }
  }

  private void dfs(TreeNode root, int K, int distance, Map<TreeNode, Integer> nodeToDistance, List<Integer> ans) {
    if (root == null)
      return;

    if (nodeToDistance.containsKey(root))
      distance = nodeToDistance.get(root);
    if (distance == K)
      ans.add(root.val);

    dfs(root.left, K, distance + 1, nodeToDistance, ans);
    dfs(root.right, K, distance + 1, nodeToDistance, ans);
  }
}