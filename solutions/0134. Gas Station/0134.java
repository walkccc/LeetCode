class Solution {
  public int canCompleteCircuit(int[] gas, int[] cost) {
    final int gasses = Arrays.stream(gas).sum();
    final int costs = Arrays.stream(cost).sum();
    if (gasses - costs < 0)
      return -1;

    int ans = 0;
    int sum = 0;

    // try to start from each index
    for (int i = 0; i < gas.length; ++i) {
      sum += gas[i] - cost[i];
      if (sum < 0) {
        sum = 0;
        ans = i + 1; // start from next index
      }
    }

    return ans;
  }
}
