class Solution {
 public:
  int minimumOperations(vector<int>& nums) {
    unordered_set<int> seen(nums.begin(), nums.end());
    return seen.size() - seen.contains(0);
  }
};
