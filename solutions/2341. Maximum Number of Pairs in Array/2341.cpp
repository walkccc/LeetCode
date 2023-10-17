class Solution {
 public:
  vector<int> numberOfPairs(vector<int>& nums) {
    constexpr int kMax = 100;
    vector<int> ans(2);
    vector<int> count(kMax + 1);

    for (const int num : nums)
      ++count[num];

    for (int i = 0; i <= kMax; ++i) {
      ans[0] += count[i] / 2;
      ans[1] += count[i] & 1;
    }

    return ans;
  }
};
