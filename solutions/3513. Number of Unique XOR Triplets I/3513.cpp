class Solution {
 public:
  int uniqueXorTriplets(vector<int>& nums) {
    const int n = nums.size();
    if (n < 3)
      return n;
    return 1 << (static_cast<int>(log2(n)) + 1);
  }
};
