class Solution {
  public int depthSum(List<NestedInteger> nestedList) {
    int ans = 0;
    int depth = 0;
    Queue<NestedInteger> q = new ArrayDeque<>();

    addIntegers(q, nestedList);

    while (!q.isEmpty()) {
      ++depth;
      for (int sz = q.size(); sz > 0; --sz) {
        final NestedInteger ni = q.poll();
        if (ni.isInteger())
          ans += ni.getInteger() * depth;
        else
          addIntegers(q, ni.getList());
      }
    }

    return ans;
  }

  private void addIntegers(Queue<NestedInteger> q, List<NestedInteger> nestedList) {
    for (final NestedInteger ni : nestedList)
      q.offer(ni);
  }
}
