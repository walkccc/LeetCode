class Solution {
 public:
  bool splitArray(vector<int>& nums) {
    const int n = nums.size();
    if (n < 7)
      return false;

    vector<int> prefix(n);

    partial_sum(nums.begin(), nums.end(), prefix.begin());

    for (int j = 3; j < n - 3; ++j) {
      unordered_set<int> seen;
      for (int i = 1; i < j - 1; ++i)
        if (prefix[i - 1] == prefix[j - 1] - prefix[i])
          seen.insert(prefix[i - 1]);
      for (int k = j + 2; k < n - 1; ++k)
        if (prefix[n - 1] - prefix[k] == prefix[k - 1] - prefix[j] &&
            seen.contains(prefix[k - 1] - prefix[j]))
          return true;
    }

    return false;
  }
};
