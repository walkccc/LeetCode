class Solution {
 public:
  int countSubranges(vector<int>& nums1, vector<int>& nums2) {
    constexpr int kMod = 1'000'000'007;
    int ans = 0;
    // {sum, count}, add if choose from nums1, minus if choose from nums2
    unordered_map<int, int> dp;

    for (int i = 0; i < nums1.size(); ++i) {
      unordered_map<int, int> newDp;
      ++newDp[nums1[i]];
      ++newDp[-nums2[i]];

      for (const auto& [prevSum, count] : dp) {
        // Choose nums1[i]
        newDp[prevSum + nums1[i]] += count;
        newDp[prevSum + nums1[i]] %= kMod;
        // Choose nums2[i]
        newDp[prevSum - nums2[i]] += count;
        newDp[prevSum - nums2[i]] %= kMod;
      }

      dp = move(newDp);
      if (const auto it = dp.find(0); it != cend(dp)) {
        ans += it->second;
        ans %= kMod;
      }
    }

    return ans;
  }
};
