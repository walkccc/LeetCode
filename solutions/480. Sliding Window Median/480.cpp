class Solution {
 public:
  vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    vector<double> ans;
    multiset<double> window(nums.begin(), nums.begin() + k);
    auto it = next(window.begin(), (k - 1) / 2);

    for (int i = k;; ++i) {
      const double median = k & 1 ? *it : (*it + *next(it)) / 2.0;
      ans.push_back(median);
      if (i == nums.size())
        break;
      window.insert(nums[i]);
      if (nums[i] < *it)
        --it;
      if (nums[i - k] <= *it)
        ++it;
      window.erase(window.lower_bound(nums[i - k]));
    }

    return ans;
  }
};
