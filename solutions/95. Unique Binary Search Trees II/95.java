class Solution {
  public List<TreeNode> generateTrees(int n) {
    if (n == 0)
      return new ArrayList<>();
    return generateTrees(1, n);
  }

  private List<TreeNode> generateTrees(int min, int max) {
    if (min > max)
      return Arrays.asList((TreeNode) null);

    List<TreeNode> ans = new ArrayList<>();

    for (int i = min; i <= max; ++i)
      for (TreeNode left : generateTrees(min, i - 1))
        for (TreeNode right : generateTrees(i + 1, max)) {
          ans.add(new TreeNode(i));
          ans.get(ans.size() - 1).left = left;
          ans.get(ans.size() - 1).right = right;
        }

    return ans;
  }
}
