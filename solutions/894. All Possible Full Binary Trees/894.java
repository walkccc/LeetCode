class Solution {
  public List<TreeNode> allPossibleFBT(int n) {
    if (n % 2 == 0)
      return new ArrayList<>();
    if (n == 1)
      return Arrays.asList(new TreeNode(0));
    if (mem.containsKey(n))
      return mem.get(n);

    List<TreeNode> ans = new ArrayList<>();

    for (int leftCount = 0; leftCount < n; ++leftCount) {
      final int rightCount = n - 1 - leftCount;
      for (TreeNode left : allPossibleFBT(leftCount))
        for (TreeNode right : allPossibleFBT(rightCount)) {
          ans.add(new TreeNode(0));
          ans.get(ans.size() - 1).left = left;
          ans.get(ans.size() - 1).right = right;
        }
    }

    mem.put(n, ans);
    return ans;
  }

  private Map<Integer, List<TreeNode>> mem = new HashMap<>();
}
