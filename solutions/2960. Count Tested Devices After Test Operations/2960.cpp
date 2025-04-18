class Solution {
 public:
  int countTestedDevices(vector<int>& batteryPercentages) {
    int ans = 0;

    for (const int batteryPercentage : batteryPercentages)
      if (batteryPercentage - ans > 0)
        ++ans;

    return ans;
  }
};
