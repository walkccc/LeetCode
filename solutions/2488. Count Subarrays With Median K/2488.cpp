class Solution {
 public:
  int countSubarrays(vector<int>& nums, int k) {
    const int kIndex = find(nums.begin(), nums.end(), k) - nums.begin();
    int ans = 0;
    unordered_map<int, int> count;

    for (int i = kIndex, balance = 0; i >= 0; --i) {
      if (nums[i] < k)
        --balance;
      else if (nums[i] > k)
        ++balance;
      ++count[balance];
    }

    for (int i = kIndex, balance = 0; i < nums.size(); ++i) {
      if (nums[i] < k)
        --balance;
      else if (nums[i] > k)
        ++balance;
      // The subarray that has balance == 0 or 1 having median equal to k.
      // So, add count[0 - balance] and count[1 - balance] to `ans`.
      ans += count[-balance] + count[1 - balance];
    }

    return ans;
  }
};
