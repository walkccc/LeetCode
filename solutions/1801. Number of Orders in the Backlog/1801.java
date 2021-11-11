class Solution {
  public int getNumberOfBacklogOrders(int[][] orders) {
    final int kMod = (int) 1e9 + 7;
    int ans = 0;

    // max-heap
    PriorityQueue<int[]> buys = new PriorityQueue<>((a, b) -> b[0] - a[0]);

    // min-heap
    PriorityQueue<int[]> sells = new PriorityQueue<>((a, b) -> a[0] - b[0]);

    for (int[] order : orders) {
      if (order[2] == 0)
        buys.offer(order);
      else
        sells.offer(order);
      while (!buys.isEmpty() && !sells.isEmpty() && buys.peek()[0] >= sells.peek()[0]) {
        final int minAmount = Math.min(buys.peek()[1], sells.peek()[1]);
        buys.peek()[1] -= minAmount;
        sells.peek()[1] -= minAmount;
        if (buys.peek()[1] == 0)
          buys.poll();
        if (sells.peek()[1] == 0)
          sells.poll();
      }
    }

    while (!buys.isEmpty())
      ans = (ans + buys.poll()[1]) % kMod;

    while (!sells.isEmpty())
      ans = (ans + sells.poll()[1]) % kMod;

    return ans;
  }
}
