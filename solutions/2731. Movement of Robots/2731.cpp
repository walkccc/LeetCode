class Solution {
 public:
  int sumDistance(vector<int>& nums, string s, int d) {
    constexpr int kMod = 1'000'000'007;
    const int n = nums.size();
    int ans = 0;
    int prefix = 0;
    vector<int> pos;

    for (int i = 0; i < nums.size(); ++i)
      if (s[i] == 'L')
        pos.push_back(nums[i] - d);
      else
        pos.push_back(nums[i] + d);

    ranges::sort(pos);

    for (int i = 0; i < n; ++i) {
      ans = ((ans + 1LL * i * pos[i] - prefix) % kMod + kMod) % kMod;
      prefix = ((0LL + prefix + pos[i]) % kMod + kMod) % kMod;
    }

    return ans;
  }
};
