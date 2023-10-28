class Solution {
  public int mincostTickets(int[] days, int[] costs) {
    int ans = 0;
    Queue<int[]> last7 = new ArrayDeque<>(); // [day, cost]
    Queue<int[]> last30 = new ArrayDeque<>();

    for (int day : days) {
      while (!last7.isEmpty() && last7.peek()[0] + 7 <= day)
        last7.poll();
      while (!last30.isEmpty() && last30.peek()[0] + 30 <= day)
        last30.poll();
      last7.offer(new int[] {day, ans + costs[1]});
      last30.offer(new int[] {day, ans + costs[2]});
      ans = Math.min(ans + costs[0], Math.min(last7.peek()[1], last30.peek()[1]));
    }

    return ans;
  }
}
