class Solution {
 public:
  int threeSumClosest(vector<int>& nums, int target) {
    int ans = nums[0] + nums[1] + nums[2];

    sort(begin(nums), end(nums));

    for (int i = 0; i + 2 < nums.size(); ++i) {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      // choose nums[i] as the first num in the triplet,
      // and search the remaining nums in [i + 1, n - 1]
      int l = i + 1;
      int r = nums.size() - 1;
      while (l < r) {
        const int sum = nums[i] + nums[l] + nums[r];
        if (sum == target)
          return sum;
        if (abs(sum - target) < abs(ans - target))
          ans = sum;
        if (sum < target)
          ++l;
        else
          --r;
      }
    }

    return ans;
  }
};
