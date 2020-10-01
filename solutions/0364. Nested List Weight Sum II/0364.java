class Solution {
  public int depthSumInverse(List<NestedInteger> nestedList) {
    int ans = 0;
    int prevSum = 0;
    Queue<NestedInteger> q = new LinkedList<>(nestedList);

    while (!q.isEmpty()) {
      for (int i = q.size(); i > 0; --i) {
        final NestedInteger ni = q.poll();
        if (ni.isInteger())
          prevSum += ni.getInteger();
        else
          q.addAll(ni.getList());
      }
      ans += prevSum;
    }

    return ans;
  }
}