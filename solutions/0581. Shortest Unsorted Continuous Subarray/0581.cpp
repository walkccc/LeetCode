class Solution {
 public:
  int findUnsortedSubarray(vector<int>& nums) {
    const int n = nums.size();
    int mini = INT_MAX;
    int maxi = INT_MIN;
    bool meetDecrease = false;
    bool meetIncrease = false;

    for (int i = 1; i < n; ++i) {
      if (nums[i] < nums[i - 1])
        meetDecrease = true;
      if (meetDecrease)
        mini = min(mini, nums[i]);
    }

    for (int i = n - 2; i >= 0; --i) {
      if (nums[i] > nums[i + 1])
        meetIncrease = true;
      if (meetIncrease)
        maxi = max(maxi, nums[i]);
    }

    int l;
    for (l = 0; l < n; ++l)
      if (nums[l] > mini)
        break;

    int r;
    for (r = n - 1; r >= 0; --r)
      if (nums[r] < maxi)
        break;

    return l < r ? r - l + 1 : 0;
  }
};
