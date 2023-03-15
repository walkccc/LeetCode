class Solution {
 public:
  bool divideArray(vector<int>& nums) {
    vector<int> count(501);

    for (const int num : nums)
      ++count[num];

    return all_of(begin(count), end(count), [](int c) { return c % 2 == 0; });
  }
};
