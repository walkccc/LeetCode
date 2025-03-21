class Solution {
  public int canCompleteCircuit(int[] gas, int[] cost) {
    final int gasSum = Arrays.stream(gas).sum();
    final int costSum = Arrays.stream(cost).sum();
    if (gasSum - costSum < 0)
      return -1;

    int ans = 0;
    int sum = 0;

    // Try to start from each index.
    for (int i = 0; i < gas.length; ++i) {
      sum += gas[i] - cost[i];
      if (sum < 0) {
        sum = 0;
        ans = i + 1; // Start from the next index.
      }
    }

    return ans;
  }
}
