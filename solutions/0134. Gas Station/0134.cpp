class Solution {
 public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    const int gasses = accumulate(gas.begin(), gas.end(), 0);
    const int costs = accumulate(cost.begin(), cost.end(), 0);
    if (gasses - costs < 0)
      return -1;

    int ans = 0;
    int sum = 0;

    // Try to start from each index
    for (int i = 0; i < gas.size(); ++i) {
      sum += gas[i] - cost[i];
      if (sum < 0) {
        sum = 0;
        ans = i + 1;  // Start from next index
      }
    }

    return ans;
  }
};
