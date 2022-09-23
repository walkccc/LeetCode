class Solution {
 public:
  vector<int> singleNumber(vector<int>& nums) {
    const int xors = accumulate(begin(nums), end(nums), 0, bit_xor<>());
    const int lowbit = xors & -xors;
    vector<int> ans(2);

    // seperate nums into two groups by the lowbit
    for (const int num : nums)
      if (num & lowbit)
        ans[0] ^= num;
      else
        ans[1] ^= num;

    return ans;
  }
};
