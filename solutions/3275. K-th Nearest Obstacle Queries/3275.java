class Solution {
  public int[] resultsArray(int[][] queries, int k) {
    int[] ans = new int[queries.length];
    Queue<Integer> maxHeap = new PriorityQueue<>(Comparator.reverseOrder());

    for (int i = 0; i < queries.length; ++i) {
      final int x = queries[i][0];
      final int y = queries[i][1];
      maxHeap.offer(Math.abs(x) + Math.abs(y));
      if (maxHeap.size() > k)
        maxHeap.poll();
      ans[i] = maxHeap.size() == k ? maxHeap.peek() : -1;
    }

    return ans;
  }
}
