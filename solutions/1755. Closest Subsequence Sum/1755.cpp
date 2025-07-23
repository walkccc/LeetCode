class Solution {
 public:
  int minAbsDifference(vector<int>& nums, int goal) {
    const int n = nums.size() / 2;
    const vector<int> lNums(nums.begin(), nums.begin() + n);
    const vector<int> rNums(nums.begin() + n, nums.end());
    int ans = INT_MAX;
    vector<int> lSums;
    vector<int> rSums;

    dfs(lNums, 0, 0, lSums);
    dfs(rNums, 0, 0, rSums);
    ranges::sort(rSums);

    for (const int lSum : lSums) {
      const int i = firstGreaterEqual(rSums, goal - lSum);
      if (i < rSums.size())  // 2^n
        ans = min(ans, abs(goal - lSum - rSums[i]));
      if (i > 0)
        ans = min(ans, abs(goal - lSum - rSums[i - 1]));
    }

    return ans;
  }

 private:
  void dfs(const vector<int>& arr, int i, int path, vector<int>& sums) {
    if (i == arr.size()) {
      sums.push_back(path);
      return;
    }
    dfs(arr, i + 1, path + arr[i], sums);
    dfs(arr, i + 1, path, sums);
  }

  int firstGreaterEqual(const vector<int>& arr, int target) {
    return ranges::lower_bound(arr, target) - arr.begin();
  }
};
