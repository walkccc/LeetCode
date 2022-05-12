class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    vector<int> path;

    sort(begin(nums), end(nums));
    nSum(nums, 4, target, 0, nums.size() - 1, path, ans);
    return ans;
  }

 private:
  // in [l, r], find n numbers add up to the target
  void nSum(const vector<int>& nums, int n, int target, int l, int r,
            vector<int>& path, vector<vector<int>>& ans) {
    if (r - l + 1 < n || target < nums[l] * n || target > nums[r] * n)
      return;
    if (n == 2) {
      // very similar to the sub procedure in 15. 3Sum
      while (l < r) {
        const int sum = nums[l] + nums[r];
        if (sum == target) {
          path.push_back(nums[l]);
          path.push_back(nums[r]);
          ans.push_back(path);
          path.pop_back();
          path.pop_back();
          ++l;
          --r;
          while (l < r && nums[l] == nums[l - 1])
            ++l;
          while (l < r && nums[r] == nums[r + 1])
            --r;
        } else if (sum < target) {
          ++l;
        } else {
          --r;
        }
      }
      return;
    }

    for (int i = l; i <= r; ++i) {
      if (i > l && nums[i] == nums[i - 1])
        continue;
      path.push_back(nums[i]);
      nSum(nums, n - 1, target - nums[i], i + 1, r, path, ans);
      path.pop_back();
    }
  }
};
