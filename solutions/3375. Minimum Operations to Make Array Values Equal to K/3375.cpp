class Solution {
 public:
  int minOperations(vector<int>& nums, int k) {
    const unordered_set<int> numsSet{nums.begin(), nums.end()};
    const int mn = ranges::min(nums);
    if (mn < k)
      return -1;
    if (mn > k)
      return numsSet.size();
    return numsSet.size() - 1;
  }
};
