class Solution {
 public:
  int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
    vector<int> mem(1 << nums2.size(), INT_MAX);
    return minimumXORSum(nums1, nums2, 0, mem);
  }

 private:
  int minimumXORSum(const vector<int>& nums1, const vector<int>& nums2,
                    unsigned mask, vector<int>& mem) {
    const int i = popcount(mask);
    if (i == nums1.size())
      return 0;
    if (mem[mask] < INT_MAX)
      return mem[mask];

    for (int j = 0; j < nums2.size(); ++j)
      if ((mask >> j & 1) == 0)
        mem[mask] =
            min(mem[mask], (nums1[i] ^ nums2[j]) +
                               minimumXORSum(nums1, nums2, mask | 1 << j, mem));

    return mem[mask];
  }
};
