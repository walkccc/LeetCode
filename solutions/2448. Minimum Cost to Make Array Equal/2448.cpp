class Solution {
 public:
  long long minCost(vector<int>& nums, vector<int>& cost) {
    long ans = 0;
    int l = ranges::min(nums);
    int r = ranges::max(nums);

    while (l < r) {
      const int m = (l + r) / 2;
      const long cost1 = getCost(nums, cost, m);
      const long cost2 = getCost(nums, cost, m + 1);
      ans = min(cost1, cost2);
      if (cost1 < cost2)
        r = m;
      else
        l = m + 1;
    }

    return ans;
  }

 private:
  long getCost(const vector<int>& nums, const vector<int>& cost, int target) {
    long res = 0;
    for (int i = 0; i < nums.size(); ++i)
      res += static_cast<long>(abs(nums[i] - target)) * cost[i];
    return res;
  }
};
