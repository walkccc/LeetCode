class Solution {
 public:
  int semiOrderedPermutation(vector<int>& nums) {
    const int n = nums.size();
    const int index1 = find(begin(nums), end(nums), 1) - begin(nums);
    const int indexN = find(begin(nums), end(nums), n) - begin(nums);
    return index1 + (n - 1 - indexN) - (index1 > indexN ? 1 : 0);
  }
};
