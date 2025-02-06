class Solution {
 public:
  int arithmeticTriplets(vector<int>& nums, int diff) {
    constexpr int kMax = 200;
    int ans = 0;
    vector<bool> count(kMax + 1);

    for (const int num : nums) {
      if (num >= 2 * diff && count[num - diff] && count[num - 2 * diff])
        ++ans;
      count[num] = true;
    }

    return ans;
  }
};
