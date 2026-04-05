class Solution {
  public int mincostTickets(int[] days, int[] costs) {
    int ans = 0;
    Queue<Pair<Integer, Integer>> last7 = new ArrayDeque<>(); // [day, cost]
    Queue<Pair<Integer, Integer>> last30 = new ArrayDeque<>();

    for (final int day : days) {
      while (!last7.isEmpty() && last7.peek().getKey() + 7 <= day)
        last7.poll();
      while (!last30.isEmpty() && last30.peek().getKey() + 30 <= day)
        last30.poll();
      last7.offer(new Pair<>(day, ans + costs[1]));
      last30.offer(new Pair<>(day, ans + costs[2]));
      ans = Math.min(ans + costs[0], Math.min(last7.peek().getValue(), last30.peek().getValue()));
    }

    return ans;
  }
}
