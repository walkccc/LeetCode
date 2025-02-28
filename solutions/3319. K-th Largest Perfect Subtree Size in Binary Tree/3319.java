record T(boolean isPerfect, int sz) {}

class Solution {
  public int kthLargestPerfectSubtree(TreeNode root, int k) {
    List<Integer> ans = new ArrayList<>();
    dfs(root, ans);
    Collections.sort(ans, Collections.reverseOrder());
    return ans.size() < k ? -1 : ans.get(k - 1);
  }

  private T dfs(TreeNode root, List<Integer> ans) {
    if (root == null)
      return new T(true, 0);
    T l = dfs(root.left, ans);
    T r = dfs(root.right, ans);
    if (l.isPerfect() && r.isPerfect() && l.sz() == r.sz()) {
      final int sz = 1 + l.sz() + r.sz();
      ans.add(sz);
      return new T(true, sz);
    }
    return new T(false, 0);
  }
}
