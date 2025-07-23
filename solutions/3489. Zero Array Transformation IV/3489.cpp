class Solution {
 public:
  int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    if (all_of(nums.begin(), nums.end(), [](int num) { return num == 0; }))
      return 0;

    const int n = nums.size();
    vector<unordered_set<int>> subsetSums(n);

    for (int i = 0; i < n; ++i)
      subsetSums[i].insert(0);

    for (int k = 0; k < queries.size(); ++k) {
      const int l = queries[k][0];
      const int r = queries[k][1];
      const int val = queries[k][2];
      for (int i = l; i <= r; ++i) {
        vector<int> sums;
        for (const int subsetSum : subsetSums[i])
          sums.push_back(subsetSum + val);
        for (const int sum : sums)
          subsetSums[i].insert(sum);
      }
      if (canFormAllNumbers(subsetSums, nums))
        return k + 1;
    }

    return -1;
  }

  bool canFormAllNumbers(const vector<unordered_set<int>>& subsetSums,
                         const vector<int>& nums) {
    for (int i = 0; i < nums.size(); ++i)
      if (!subsetSums[i].contains(nums[i]))
        return false;
    return true;
  }
};
