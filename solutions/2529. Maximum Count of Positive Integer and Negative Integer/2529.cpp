class Solution {
 public:
  int maximumCount(vector<int>& nums) {
    return max(
        count_if(begin(nums), end(nums), [](int num) { return num > 0; }),
        count_if(begin(nums), end(nums), [](int num) { return num < 0; }));
  }
};
