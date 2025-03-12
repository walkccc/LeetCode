class Solution {
 public:
  int partitionDisjoint(vector<int>& nums) {
    const int n = nums.size();
    vector<int> mn(n);
    mn[n - 1] = nums[n - 1];
    int mx = INT_MIN;

    for (int i = n - 2; i >= 0; --i)
      mn[i] = min(mn[i + 1], nums[i]);

    for (int i = 0; i < n; ++i) {
      mx = max(mx, nums[i]);
      if (mx <= mn[i + 1])
        return i + 1;
    }

    throw;
  }
};
