class Solution {
 public:
  int minMoves(vector<int>& nums) {
    const int min = *min_element(begin(nums), end(nums));
    return accumulate(begin(nums), end(nums), 0,
                      [&](int a, int b) { return a + (b - min); });
  }
};
