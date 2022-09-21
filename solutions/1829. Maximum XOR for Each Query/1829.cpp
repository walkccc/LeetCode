class Solution {
 public:
  vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
    const int max = (1 << maximumBit) - 1;
    vector<int> ans;
    int xors = 0;

    for (const int num : nums) {
      xors ^= num;
      ans.push_back(xors ^ max);
    }

    reverse(begin(ans), end(ans));
    return ans;
  }
};
