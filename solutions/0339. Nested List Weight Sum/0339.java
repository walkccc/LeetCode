class Solution {
  public int depthSum(List<NestedInteger> nestedList) {
    int ans = 0;
    int depth = 0;
    Queue<NestedInteger> q = new LinkedList<>();

    addIntegers(q, nestedList);

    while (!q.isEmpty()) {
      ++depth;
      for (int size = q.size(); size > 0; --size) {
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
