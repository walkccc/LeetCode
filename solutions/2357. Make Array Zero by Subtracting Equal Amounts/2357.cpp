class Solution {
 public:
  int minimumOperations(vector<int>& nums) {
    unordered_set<int> seen(begin(nums), end(nums));
    return seen.size() - seen.count(0);
  }
};
