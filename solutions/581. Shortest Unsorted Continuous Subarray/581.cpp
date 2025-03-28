class Solution {
 public:
  int findUnsortedSubarray(vector<int>& nums) {
    const int n = nums.size();
    int mn = INT_MAX;
    int mx = INT_MIN;
    bool meetDecrease = false;
    bool meetIncrease = false;

    for (int i = 1; i < n; ++i) {
      if (nums[i] < nums[i - 1])
        meetDecrease = true;
      if (meetDecrease)
        mn = min(mn, nums[i]);
    }

    for (int i = n - 2; i >= 0; --i) {
      if (nums[i] > nums[i + 1])
        meetIncrease = true;
      if (meetIncrease)
        mx = max(mx, nums[i]);
    }

    int l;
    for (l = 0; l < n; ++l)
      if (nums[l] > mn)
        break;

    int r;
    for (r = n - 1; r >= 0; --r)
      if (nums[r] < mx)
        break;

    return l < r ? r - l + 1 : 0;
  }
};
