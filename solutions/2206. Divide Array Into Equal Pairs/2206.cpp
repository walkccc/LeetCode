class Solution {
 public:
  bool divideArray(vector<int>& nums) {
    vector<int> count(501);

    for (const int num : nums)
      ++count[num];

    return ranges::all_of(count, [](int c) { return c % 2 == 0; });
  }
};
