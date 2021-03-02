class Solution {
 public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    const int gasses = accumulate(begin(gas), end(gas), 0);
    const int costs = accumulate(begin(cost), end(cost), 0);
    if (gasses - costs < 0)
      return -1;

    int ans = 0;
    int sum = 0;

    // try to start from each index
    for (int i = 0; i < gas.size(); ++i) {
      sum += gas[i] - cost[i];
      if (sum < 0) {
        sum = 0;
        ans = i + 1;  // start from next index
      }
    }

    return ans;
  }
};
