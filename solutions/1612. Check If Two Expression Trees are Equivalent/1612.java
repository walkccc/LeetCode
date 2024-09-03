class Solution {
  public boolean checkEquivalence(Node root1, Node root2) {
    int[] count = new int[26];
    dfs(root1, count, 1);
    dfs(root2, count, -1);
    return Arrays.stream(count).filter(c -> c != 0).count() == 0;
  }

  private void dfs(Node root, int[] count, int add) {
    if (root == null)
      return;
    if ('a' <= root.val && root.val <= 'z')
      count[root.val - 'a'] += add;
    dfs(root.left, count, add);
    dfs(root.right, count, add);
  }
}
