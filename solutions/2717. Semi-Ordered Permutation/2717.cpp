class Solution {
 public:
  int semiOrderedPermutation(vector<int>& nums) {
    const int n = nums.size();
    const int index1 = find(nums.begin(), nums.end(), 1) - nums.begin();
    const int indexN = find(nums.begin(), nums.end(), n) - nums.begin();
    return index1 + (n - 1 - indexN) - (index1 > indexN ? 1 : 0);
  }
};
