class Solution {
  public int minDayskVariants(int[][] points, int k) {
    final int kMax = 100;
    int ans = Integer.MAX_VALUE;

    for (int a = 1; a <= kMax; ++a)
      for (int b = 1; b <= kMax; ++b) {
        // Stores the k minimum distances of points that can reach (a, b).
        Queue<Integer> maxHeap = new PriorityQueue<>(Collections.reverseOrder());
        for (int[] point : points) {
          final int x = point[0];
          final int y = point[1];
          maxHeap.offer(Math.abs(x - a) + Math.abs(y - b));
          if (maxHeap.size() > k)
            maxHeap.poll();
        }
        ans = Math.min(ans, maxHeap.peek());
      }

    return ans;
  }
}
