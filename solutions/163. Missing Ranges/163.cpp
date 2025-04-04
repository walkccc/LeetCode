class Solution {
 public:
  vector<vector<int>> findMissingRanges(vector<int>& nums, int lower,
                                        int upper) {
    if (nums.empty())
      return {getRange(lower, upper)};

    vector<vector<int>> ans;

    if (nums.front() > lower)
      ans.push_back(getRange(lower, nums.front() - 1));

    for (int i = 1; i < nums.size(); ++i)
      if (nums[i] > nums[i - 1] + 1)
        ans.push_back(getRange(nums[i - 1] + 1, nums[i] - 1));

    if (nums.back() < upper)
      ans.push_back(getRange(nums.back() + 1, upper));

    return ans;
  }

 private:
  vector<int> getRange(int lo, int hi) {
    if (lo == hi)
      return vector<int>{lo, lo};
    return vector<int>{lo, hi};
  }
};
