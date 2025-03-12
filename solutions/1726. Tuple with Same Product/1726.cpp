class Solution {
 public:
  int tupleSameProduct(vector<int>& nums) {
    int ans = 0;
    unordered_map<int, int> count;

    for (int i = 0; i < nums.size(); ++i)
      for (int j = 0; j < i; ++j)
        ans += count[nums[i] * nums[j]]++ * 8;

    return ans;
  }
};
