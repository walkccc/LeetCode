class Solution {
 public:
  int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
    constexpr int kMod = 1'000'000'007;
    long ans = 0;
    // count[i] := the number of times nums[i] has been requested
    vector<int> count(nums.size());

    for (const vector<int>& request : requests) {
      const int start = request[0];
      const int end = request[1];
      ++count[start];
      if (end + 1 < nums.size())
        --count[end + 1];
    }

    for (int i = 1; i < nums.size(); ++i)
      count[i] += count[i - 1];

    ranges::sort(count);
    ranges::sort(nums);

    for (int i = 0; i < nums.size(); ++i) {
      ans += static_cast<long>(nums[i]) * count[i];
      ans %= kMod;
    }

    return ans;
  }
};
