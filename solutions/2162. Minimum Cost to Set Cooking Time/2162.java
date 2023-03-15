class Solution {
  public int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
    int ans = Integer.MAX_VALUE;
    int mins = targetSeconds > 5999 ? 99 : targetSeconds / 60;
    int secs = targetSeconds - mins * 60;

    while (secs < 100) {
      ans = Math.min(ans, getCost(startAt, moveCost, pushCost, mins, secs));
      --mins;
      secs += 60;
    }

    return ans;
  }

  private int getCost(int startAt, int moveCost, int pushCost, int mins, int secs) {
    int cost = 0;
    char curr = (char) ('0' + startAt);
    for (final char c : String.valueOf(mins * 100 + secs).toCharArray())
      if (c == curr) {
        cost += pushCost;
      } else {
        cost += moveCost + pushCost;
        curr = c;
      }
    return cost;
  };
}
