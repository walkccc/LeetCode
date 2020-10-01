class Solution {
  public int depthSum(List<NestedInteger> nestedList) {
    int depth = 1;
    Queue<NestedInteger> q = new LinkedList<>();

    addInteger(nestedList, q, depth);

    while (!q.isEmpty()) {
      ++depth;
      for (int i = q.size(); i > 0; --i) {
        final NestedInteger ni = q.poll();
        addInteger(ni.getList(), q, depth);
      }
    }

    return ans;
  }

  private int ans = 0;

  private void addInteger(final List<NestedInteger> nestedList, Queue<NestedInteger> q, int depth) {
    for (final NestedInteger ni : nestedList)
      if (ni.isInteger())
        ans += ni.getInteger() * depth;
      else
        q.offer(ni);
  }
}