class FenwickTree {
 public:
  FenwickTree(int n) : vals(n + 1) {}

  // Updates the maximum sum of subsequence ending in (i - 1) with `val`.
  void maximize(int i, long val) {
    while (i < vals.size()) {
      vals[i] = max(vals[i], val);
      i += lowbit(i);
    }
  }

  // Returns the maximum sum of subsequence ending in (i - 1).
  long get(int i) const {
    long res = 0;
    while (i > 0) {
      res = max(res, vals[i]);
      i -= lowbit(i);
    }
    return res;
  }

 private:
  vector<long> vals;

  static int lowbit(int i) {
    return i & -i;
  }
};

class Solution {
 public:
  long long maxBalancedSubsequenceSum(vector<int>& nums) {
    // Let's define maxSum[i] := subsequence with the maximum sum ending in i
    // By observation:
    //     nums[i] - nums[j] >= i - j
    //  => nums[i] - i >= nums[j] - j
    //  So, if nums[i] - i >= nums[j] - j, where i > j,
    //  maxSum[i] = max(maxSum[i], maxSum[j] + nums[i])
    long ans = LONG_MIN;
    FenwickTree tree(nums.size());

    for (const auto& [_, i] : getPairs(nums)) {
      const long subseqSum = tree.get(i) + nums[i];
      tree.maximize(i + 1, subseqSum);
      ans = max(ans, subseqSum);
    }

    return ans;
  }

 private:
  vector<pair<int, int>> getPairs(const vector<int>& nums) {
    vector<pair<int, int>> pairs;
    for (int i = 0; i < nums.size(); ++i)
      pairs.emplace_back(nums[i] - i, i);
    ranges::sort(pairs);
    return pairs;
  }
};
