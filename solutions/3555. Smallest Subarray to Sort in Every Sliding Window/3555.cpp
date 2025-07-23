class Solution {
 public:
  vector<int> minSubarraySort(vector<int>& nums, int k) {
    const int n = nums.size();
    vector<int> ans;

    for (int i = 0; i <= n - k; ++i) {
      vector<int> window(nums.begin() + i, nums.begin() + i + k);
      vector<int> sortedWindow = window;
      ranges::sort(sortedWindow);
      int l = 0;
      int r = k - 1;
      while (l < k && window[l] == sortedWindow[l])
        ++l;
      while (r >= 0 && window[r] == sortedWindow[r])
        --r;
      ans.push_back(l > r ? 0 : r - l + 1);
    }

    return ans;
  }
};
