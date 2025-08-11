class Solution {
 public:
  int maxGoodNumber(vector<int>& nums) {
    int ans = 0;

    ranges::sort(nums,
                 [this](int a, int b) { return concat(a, b) > concat(b, a); });

    for (const int num : nums)
      ans = concat(ans, num);

    return ans;
  }

 private:
  // Returns the concatenation of the binary representations of a and b.
  int concat(int a, int b) {
    return (a << static_cast<int>(log2(b)) + 1) + b;
  }
};
