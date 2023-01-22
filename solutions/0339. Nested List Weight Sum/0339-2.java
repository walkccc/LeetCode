class Solution {
  public int depthSum(List<NestedInteger> nestedList) {
    dfs(nestedList, 1);
    return ans;
  }

  private int ans = 0;

  private void dfs(final List<NestedInteger> nestedList, int depth) {
    for (final NestedInteger ni : nestedList)
      if (ni.isInteger())
        ans += ni.getInteger() * depth;
      else
        dfs(ni.getList(), depth + 1);
  }
}
