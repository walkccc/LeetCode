class Solution {
 public:
  vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l,
                                        vector<int>& r) {
    vector<bool> ans;

    for (int i = 0; i < l.size(); ++i)
      ans.push_back(isArithmetic(nums, l[i], r[i]));

    return ans;
  }

 private:
  bool isArithmetic(vector<int>& nums, int l, int r) {
    if (r - l < 2)
      return true;

    unordered_set<int> numsSet;
    int mn = INT_MAX;
    int mx = INT_MIN;

    for (int i = l; i <= r; ++i) {
      mn = min(mn, nums[i]);
      mx = max(mx, nums[i]);
      numsSet.insert(nums[i]);
    }

    if ((mx - mn) % (r - l) != 0)
      return false;

    const int interval = (mx - mn) / (r - l);

    for (int k = 1; k <= r - l; ++k)
      if (!numsSet.contains(mn + k * interval))
        return false;

    return true;
  }
};
