class Solution {
 public:
  int minimumDifference(vector<int>& nums) {
    const int n = nums.size() / 2;
    const int sum = accumulate(nums.begin(), nums.end(), 0);
    const int goal = sum / 2;
    const vector<int> lNums(nums.begin(), nums.begin() + n);
    const vector<int> rNums(nums.begin() + n, nums.end());
    int ans = INT_MAX;
    vector<vector<int>> lSums(n + 1);
    vector<vector<int>> rSums(n + 1);

    dfs(lNums, 0, 0, 0, lSums);
    dfs(rNums, 0, 0, 0, rSums);

    for (int lCount = 0; lCount <= n; ++lCount) {
      auto& l = lSums[lCount];
      auto& r = rSums[n - lCount];
      ranges::sort(r);
      for (const int lSum : l) {
        const int i = firstGreaterEqual(r, goal - lSum);
        if (i < r.size()) {
          const int sumPartOne = sum - lSum - r[i];
          const int sumPartTwo = sum - sumPartOne;
          ans = min(ans, abs(sumPartOne - sumPartTwo));
        }
        if (i > 0) {
          const int sumPartOne = sum - lSum - r[i - 1];
          const int sumPartTwo = sum - sumPartOne;
          ans = min(ans, abs(sumPartOne - sumPartTwo));
        }
      }
    }

    return ans;
  }

 private:
  void dfs(const vector<int>& A, int i, int count, int path,
           vector<vector<int>>& sums) {
    if (i == A.size()) {
      sums[count].push_back(path);
      return;
    }
    dfs(A, i + 1, count + 1, path + A[i], sums);
    dfs(A, i + 1, count, path, sums);
  }

  int firstGreaterEqual(const vector<int>& A, int target) {
    return ranges::lower_bound(A, target) - A.begin();
  }
};
