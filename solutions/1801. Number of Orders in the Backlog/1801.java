class Solution {
  public int getNumberOfBacklogOrders(int[][] orders) {
    final int MOD = 1_000_000_007;
    int ans = 0;
    Queue<int[]> buysMaxHeap = new PriorityQueue<>(Comparator.comparingInt(a -> - a[0]));
    Queue<int[]> sellsMinHeap = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));

    for (int[] order : orders) {
      if (order[2] == 0)
        buysMaxHeap.offer(order);
      else
        sellsMinHeap.offer(order);
      while (!buysMaxHeap.isEmpty() && !sellsMinHeap.isEmpty() &&
             buysMaxHeap.peek()[0] >= sellsMinHeap.peek()[0]) {
        final int minAmount = Math.min(buysMaxHeap.peek()[1], sellsMinHeap.peek()[1]);
        buysMaxHeap.peek()[1] -= minAmount;
        sellsMinHeap.peek()[1] -= minAmount;
        if (buysMaxHeap.peek()[1] == 0)
          buysMaxHeap.poll();
        if (sellsMinHeap.peek()[1] == 0)
          sellsMinHeap.poll();
      }
    }

    while (!buysMaxHeap.isEmpty()) {
      ans += buysMaxHeap.poll()[1];
      ans %= MOD;
    }

    while (!sellsMinHeap.isEmpty()) {
      ans += sellsMinHeap.poll()[1];
      ans %= MOD;
    }

    return ans;
  }
}
