class Solution {
  public int findMaxValueOfEquation(int[][] points, int k) {
    int ans = Integer.MIN_VALUE;
    // (y - x, x)
    Queue<Pair<Integer, Integer>> maxHeap = new PriorityQueue<>(
        (a, b)
            -> a.getKey().equals(b.getKey()) ? b.getValue().compareTo(a.getValue())
                                             : b.getKey().compareTo(a.getKey()));

    for (int[] p : points) {
      final int x = p[0];
      final int y = p[1];
      while (!maxHeap.isEmpty() && x - maxHeap.peek().getValue() > k)
        maxHeap.poll();
      if (!maxHeap.isEmpty())
        ans = Math.max(ans, x + y + maxHeap.peek().getKey());
      maxHeap.offer(new Pair<>(y - x, x));
    }

    return ans;
  }
}
