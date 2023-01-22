class Solution {
  public int depthSumInverse(List<NestedInteger> nestedList) {
    int ans = 0;
    int prevSum = 0;
    Queue<NestedInteger> q = new ArrayDeque<>(nestedList);

    while (!q.isEmpty()) {
      for (int sz = q.size(); sz > 0; --sz) {
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
