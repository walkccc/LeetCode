class Solution {
 public:
  int longestEqualSubarray(vector<int>& nums, int k) {
    int ans = 0;
    unordered_map<int, int> count;

    for (int l = 0, r = 0; r < nums.size(); ++r) {
      ans = max(ans, ++count[nums[r]]);
      while (r - l + 1 - k > ans)
        --count[nums[l++]];
    }

    return ans;
  }
};
