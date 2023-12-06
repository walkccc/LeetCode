class Solution {
 public:
  long long countGood(vector<int>& nums, int k) {
    long long ans = 0;
    int pairs = 0;
    unordered_map<int, int> count;

    for (int l = 0, r = 0; r < nums.size(); ++r) {
      // Since there're count[r] nums[r]s, including nums[r] to the window will
      // increase the number of good subarrays by count[r].
      pairs += count[nums[r]]++;
      while (pairs >= k)
        pairs -= --count[nums[l++]];
      // nums[0..r], nums[1..r], ..., nums[l - 1..r] are good subarrays, so add
      // l to the `ans`.
      ans += l;
    }

    return ans;
  }
};
