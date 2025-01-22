class Solution {
 public:
  bool isPossibleToSplit(vector<int>& nums) {
    constexpr int kMax = 100;
    vector<int> count(kMax + 1);

    for (const int num : nums)
      ++count[num];

    return ranges::all_of(count, [](int freq) { return freq <= 2; });
  }
};
