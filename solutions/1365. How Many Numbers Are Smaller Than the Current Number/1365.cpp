class Solution {
 public:
  vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    constexpr int kMax = 100;
    vector<int> ans;
    vector<int> count(kMax + 1);

    for (const int num : nums)
      ++count[num];

    for (int i = 1; i <= kMax; ++i)
      count[i] += count[i - 1];

    for (const int num : nums)
      ans.push_back(num == 0 ? 0 : count[num - 1]);

    return ans;
  }
};
