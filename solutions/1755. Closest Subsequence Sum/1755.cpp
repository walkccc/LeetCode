class Solution {
 public:
  int minAbsDifference(vector<int>& nums, int goal) {
    const int n = nums.size() / 2;
    const vector<int> lNums(begin(nums), begin(nums) + n);
    const vector<int> rNums(begin(nums) + n, end(nums));
    int ans = INT_MAX;
    vector<int> lSums;
    vector<int> rSums;

    dfs(lNums, 0, 0, lSums);
    dfs(rNums, 0, 0, rSums);
    sort(begin(rSums), end(rSums));

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
  void dfs(const vector<int>& A, int i, int path, vector<int>& sums) {
    if (i == A.size()) {
      sums.push_back(path);
      return;
    }
    dfs(A, i + 1, path + A[i], sums);
    dfs(A, i + 1, path, sums);
  }

  int firstGreaterEqual(const vector<int>& A, int target) {
    return lower_bound(begin(A), end(A), target) - begin(A);
  }
};
