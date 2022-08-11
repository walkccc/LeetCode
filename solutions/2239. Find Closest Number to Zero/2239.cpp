class Solution {
 public:
  int findClosestNumber(vector<int>& nums) {
    return *min_element(begin(nums), end(nums), [](const int a, const int b) {
      return abs(a) == abs(b) ? a > b : abs(a) < abs(b);
    });
  }
};
