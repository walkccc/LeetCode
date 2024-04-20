class Solution {
 public:
  vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
    const int n = nums.size();
    vector<int> ans;

    for (int i = 0, j = 0; i < n; ++i) {
      // the first index j s.t. nums[j] == key and j >= i - k
      while (j < n && (nums[j] != key || j < i - k))
        ++j;
      if (j == n)
        break;
      if (abs(i - j) <= k)
        ans.push_back(i);
    }

    return ans;
  }
};
